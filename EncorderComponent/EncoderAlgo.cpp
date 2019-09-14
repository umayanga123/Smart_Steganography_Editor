#include <opencv2/opencv.hpp>
#include <stdlib.h>
class EncorderAlgo{

public:
	int LSB_encoder(std::string text ,std::string path) {

		// Stores original image
		cv::Mat image = cv::imread(path);
		if (image.empty()) {
			return -1;
		}

		// secrect text information
		std::string word = text;
		if (word.length() < 1) {
			return -2;
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
						break;
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
		};

		// whole message was not encoded
		if (!encoded) {
			return -3;
		}

		// Writes the stegnographic image
		imwrite("out_"+ path.substr(path.find_last_of("/\\") + 1), image);

		return 0;
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
