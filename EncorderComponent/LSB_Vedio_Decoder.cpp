#include "opencv2/opencv.hpp"

class LSB_Vedio_Decoder {

	public:
		std::string decodeFrames(std::string path ,int framNo) {

			// Create a VideoCapture object and open the input file
			cv::VideoCapture cap(path);

			// Check if camera opened successfully
			if (!cap.isOpened()) {
				return "Error";
			}

			double count = cap.get(CV_CAP_PROP_FRAME_COUNT);
			if (framNo <0 || count < framNo) {
				cap.release();
				return "Max Frame count  should be:" + std::to_string(count);
			}
			
			int i = 0;
			while (1) {

				cv::Mat frame;

				// Capture frame-by-frame
				cap >> frame;

				// If the frame is empty, break immediately
				if (frame.empty()) {
					cap.release();
					break;
				}

				if (i==framNo) {
					std::string msg = LSB_Frame_decoder_algo(frame);
					cap.release();
					return msg;
				}
			
				i++;
				// Press  ESC on keyboard to exit
				char c = (char)cv::waitKey(25);
				if (c == 27)
					break;
			}
		}

	public:
		std::string  LSB_Frame_decoder_algo(cv::Mat frame) {
			// Stores original image
			cv::Mat image = frame;
			if (image.empty()) {
				return "Image Error\n";
			}

			std::string msg;
			// char to work on
			char ch = 0;
			// contains information about which bit of char to work on
			int bit_count = 0;

			/*
			To extract the message from the image, we will iterate through the pixels and extract the LSB of
			the pixel values (RGB) and this way we can get our message.
			*/
			for (int row = 0; row < image.rows; row++) {
				for (int col = 0; col < image.cols; col++) {
					for (int color = 0; color < 3; color++) {

						// stores the pixel details
						cv::Vec3b pixel = image.at<cv::Vec3b>(cv::Point(row, col));

						// manipulate char bits according to the LSB of pixel values
						if (isBitSet(pixel.val[color], 0))
							ch |= 1;

						// increment bit_count to work on next bit
						bit_count++;

						// bit_count is 8, that means we got our char from the encoded image
						if (bit_count == 8) {

							// NULL char is encountered
							if (ch == '\0')
								goto L2;

							bit_count = 0;
							msg += ch;
							ch = 0;
						}
						else {
							ch = ch << 1;
						}

					}
				}
			}L2:;


		return msg;
	}



	private:
		// Checks whether the bit is set or not at a particular position.
		// Returns true if set
		// Returns false if not set
		bool isBitSet(char ch, int pos) {
			// 7 6 5 4 3 2 1 0
			ch = ch >> pos;
			if (ch & 1)
				return true;
			return false;
		}

};