#include "opencv2/opencv.hpp"

class LSB_Vedio_Encoder {

		public:
			/*
			This functions opens a video fileand extracts the framesand put them into a vector of Mat(its the class for representing an img)
			*/
			int encodeFrames(const std::string& videoFilePath, std::string secrect) {

				try {
					//open the video file
					cv::VideoCapture cap(videoFilePath); // open the video file

					if (!cap.isOpened())  // check if we succeeded
						CV_Error(CV_StsError, "Can not open Video file");

					//
					int frame_width = static_cast<int>(cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
					int frame_height = static_cast<int>(cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT));//get the height of frames of the video

					cv::Size frame_size(frame_width, frame_height);
					double frames_per_second = cap.get(CV_CAP_PROP_FPS);
			
			
					//Create and initialize the VideoWriter object 
					cv::VideoWriter oVideoWriter("F:/out_" + videoFilePath.substr(videoFilePath.find_last_of("/\\") + 1), cv::VideoWriter::fourcc('H', 'F', 'Y', 'U'),
						frames_per_second, frame_size, true);


					//cap.get(CV_CAP_PROP_FRAME_COUNT) contains the number of frames in the video;
					for (int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum++)
					{
						cv::Mat frame;
						cap >> frame; // get the next frame from video
				
						frame = LSB_Frame_Encoder_algo(secrect, frame);
				
						//If the VideoWriter object is not initialized successfully, exit the program
						if (oVideoWriter.isOpened() == false)
						{
							return -1;
						}

						//write the video frame to the file
						oVideoWriter.write(frame);


						//Wait for for 10 milliseconds until any key is pressed.  
						//If the 'Esc' key is pressed, break the while loop.
						//If any other key is pressed, continue the loop 
						//If any key is not pressed within 10 milliseconds, continue the loop 
						if (cv::waitKey(10) == 27)
						{
							break;
						}
					}

					//Flush and close the video file
					oVideoWriter.release();
				}
				catch (cv::Exception& e) {
					return -1;
				}

				return 0;
			}


		public:
			cv::Mat LSB_Frame_Encoder_algo(std::string text, cv::Mat frame) {

				// Stores original image
				cv::Mat image = frame;

				// secrect text information
				std::string word = text;
				if (word.length() < 1) {
					return frame;
				}

				// char to work on
				char ch;
				// reads the first char from the file
				int i = 0;
				ch = word.at(i);
				i++;
				// contains information about which bit of char to work on
				int bit_count = 0;
				// to check whether file has ended
				bool last_null_char = false;
				// to check if the whole message is encoded or not
				bool encoded = false;

				/*
			To hide text into images. We are taking one char (8 bits) and each of the 8 bits are stored
			in the Least Significant Bits (LSB) of the pixel values (Red,Green,Blue).
			We are manipulating bits in such way that changing LSB of the pixel values will not make a huge difference.
			The image will still look similiar to the naked eye.
			*/

				for (int row = 0; row < image.rows; row++) {
					for (int col = 0; col < image.cols; col++) {
						for (int color = 0; color < 3; color++) {

							// stores the pixel details
							cv::Vec3b pixel = image.at<cv::Vec3b>(cv::Point(row, col));

							// if bit is 1 : change LSB of present color value to 1.
							// if bit is 0 : change LSB of present color value to 0.
							if (isBitSet(ch, 7 - bit_count))
								pixel.val[color] |= 1;
							else
								pixel.val[color] &= ~1;

							// update the image with the changed pixel values
							image.at<cv::Vec3b>(cv::Point(row, col)) = pixel;

							// increment bit_count to work on next bit
							bit_count++;

							// if last_null_char is true and bit_count is 8, then our message is successfully encode.
							if (last_null_char && bit_count == 8) {
								encoded = true;
								goto L1;
							}

							// if bit_count is 8 we pick the next char from the file and work on it
							if (bit_count == 8) {
								bit_count = 0;

								if (word.length() > i) {
									ch = word.at(i);
									i++;
								}
								else {
									last_null_char = true;
									ch = '\0';
								}
							}

						}
					}
				}L1:;

				// whole message was not encoded
				if (!encoded) {
					return frame;
				}


				return image;
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