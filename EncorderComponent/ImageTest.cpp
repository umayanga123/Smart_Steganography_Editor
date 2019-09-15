#include <opencv2/opencv.hpp>

class Test {
public:
	int A() {
		cv::Mat img = cv::imread("mario.png", cv::IMREAD_UNCHANGED);
		cv::namedWindow("image", cv::WindowFlags::WINDOW_NORMAL);
		imshow("image", img);
		return 0;
	}

public:
	int LSB_encoder(std::string text) {

		// Stores original image
		cv::Mat image = cv::imread("mario.png");
		if (image.empty()) {
			std::cout << "Image Error\n";
			exit(-1);
		}

		// Open file for text information
		std::fstream file;
		file.open("example.txt");
		if (!file.is_open()) {
			std::cout << "File Error\n";
			exit(-1);
		}

		std::string word = text;
		if (word.length() < 1) {
			std::cout << "File Error\n";
			exit(-1);
		}

		// char to work on
		char ch;
		// reads the first char from the file
		//file.get(ch);
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
						goto OUT;
					}

					// if bit_count is 8 we pick the next char from the file and work on it
					if (bit_count == 8) {
						bit_count = 0;
						//file.get(ch);
						
						
						if (word.length() > i) {
							ch = word.at(i);
							i++;
						}
						else {
							last_null_char = true;
							ch = '\0';
						}

						// if EndOfFile(EOF) is encountered insert NULL char to the image
						/*if (file.eof()) {
							last_null_char = true;
							ch = '\0';
						}*/
					}

				}
			}
		}
	OUT:;

		// whole message was not encoded
		if (!encoded) {
			std::cout << "Message too big. Try with larger image.\n";
			exit(-1);
		}

		// Writes the stegnographic image
		imwrite("output_mario.png", image);

		return 0;
	}


public:
	std::string  LSB_decoder() {
		// Stores original image
		cv::Mat image = cv::imread("output_image.png");
		if (image.empty()) {
			std::cout << "Image Error\n";
			exit(-1);
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
							goto OUT;

						bit_count = 0;
						msg +=ch;
						//std::cout << ch;
						ch = 0;
					}
					else {
						ch = ch << 1;
					}

				}
			}
		}
	OUT:;


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
