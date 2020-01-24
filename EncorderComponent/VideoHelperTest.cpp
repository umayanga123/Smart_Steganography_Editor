#include "opencv2/opencv.hpp"

/*Test class*/
class VideoHelperTest {


public:
	int readPixel() {
		cv::Mat img;

		img = cv::imread("pic_2.jpg", CV_LOAD_IMAGE_UNCHANGED);
	    //img = cv::imread("mario_l_bw.png", CV_LOAD_IMAGE_UNCHANGED);

		//
		//cv::Mat im_gray = cv::imread("c.png", CV_LOAD_IMAGE_GRAYSCALE);
		//cv::Mat img_bw = im_gray > 128;
		//imwrite("c_out.png", img_bw);

		if (img.empty()) {
			std::cout << "Error" << std::endl;
			return -1;
		}

		//cv::namedWindow("New_image", CV_WINDOW_NORMAL);
		//imshow("New_image", img);
		cv::Mat rgbchannel[3];
		// The actual splitting.
		split(img, rgbchannel);
		//cv::namedWindow("Blue", CV_WINDOW_AUTOSIZE);
		//imshow("blue", rgbchannel[0]);
		imwrite("one_lemma_pic_2.png", rgbchannel[0]);

		std::ofstream outputFile;
		outputFile.open("c.txt");



		// print number of channels in image
		//std::cout << "image channels: " << img.channels() << std::endl;
		//std::cout << "Pixel value: " << std::endl;
		outputFile << "image channels: " << img.channels() << '\n';
		outputFile << "Y: " << img.cols << '\n';
		outputFile << "X " << img.rows << '\n';
		outputFile << "Pixel value: " << '\n';

		// check if image is a single channel
		if (img.channels() == 1) {
			for (int y = 0; y < img.cols; y++) {
				for (int x = 0; x < img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Scalar pixel = img.at<uchar>(x, y);
					//std::cout << pixel.val[0] << ",";
					outputFile << pixel.val[0] << '\n';
				}
				std::cout << std::endl << '\n';
			}
		}
		else if (img.channels() == 3) {
			for (int y = 0; y < img.cols; y++) {
				for (int x = 0; x < img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]" ;
					cv::Vec3b pixel = img.at<cv::Vec3b>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];
					
					//std::cout << "[" << blue << " " << green << " " << red << "],";
					outputFile << "[" << blue << " " << green << " " << red << "]," << '\n';
				}
				//std::cout << std::endl;
				outputFile << std::endl <<'\n';
				
			}
		}
		else if (img.channels() == 4) {
			for (int y = 0; y < img.cols; y++) {
				for (int x = 0; x < img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Vec4b pixel = img.at<cv::Vec4b>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];
					int alpha = pixel.val[3];
					//std::cout << "[" << blue << " " << green << " " << red << "],";
					outputFile << "[" << blue << " " << green << " " << red << " " << alpha << "]," << '\n';
				}
				//std::cout << std::endl;
				outputFile << std::endl << '\n';

			}
		}
		else {
			std::cout << "this is not a single channel image" << std::endl;
		}

		// Close the file.
		outputFile.close();

		//cv::waitKey(0);
		return 0;


	}

public:
	int readConvertPixel() {
		cv::Mat qr_img;
		cv::Mat	cv_img;

		qr_img = cv::imread("qr.png", CV_LOAD_IMAGE_UNCHANGED);
		cv_img = cv::imread("lena.png", CV_LOAD_IMAGE_UNCHANGED);

		//
		//cv::Mat im_gray = cv::imread("mario_l.png", CV_LOAD_IMAGE_GRAYSCALE);
		//cv::Mat img_bw = im_gray > 128;
		//imwrite("mario_l_bw.png", img_bw);

		if (qr_img.empty() | cv_img.empty()) {
			std::cout << "Error" << std::endl;
			return -1;
		}

		//cv::namedWindow("New_image", CV_WINDOW_NORMAL);
		//imshow("New_image", img);
		std::ofstream outputFile;
		outputFile.open("a.txt");



		// print number of channels in image
		std::cout << "Pixel value: " << std::endl;
		outputFile << "image channels: " << cv_img.channels() << '\n';
		outputFile << "Y: " << cv_img.cols << '\n';
        outputFile << "X " << cv_img.rows << '\n';
		outputFile << "Pixel value: " << '\n';

		// check if image is a single channel
		if (qr_img.channels() == 5) {
			for (int y = 0; y < qr_img.cols; y++) {
				for (int x = 0; x < qr_img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Scalar pixel = qr_img.at<uchar>(x, y);
					//std::cout << pixel.val[0] << ",";
					outputFile << pixel.val[0] << '\n';
				}
				std::cout << std::endl << '\n';
			}
		}
		else if (cv_img.channels() == 3) {
			for (int y = 0; y < cv_img.cols; y++) {
				for (int x = 0; x < cv_img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Vec3b pixel = cv_img.at<cv::Vec3b>(x, y);
					cv::Scalar qr_pixel = qr_img.at<uchar>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];

					if (qr_pixel.val[0] == 0) {
						pixel.val[0] = 0;
						//	pixel.val[1] = 0;
						//	pixel.val[2] = 0;
					}
					else {
					//	 pixel.val[0] = 255;
						//	pixel.val[1] = 255;
						//	pixel.val[2] = 255;
					}
					cv_img.at<cv::Vec3b>(x, y) = pixel;
					//std::cout << "[" << blue << " " << green << " " << red << "],";
					outputFile << "[" << blue << " " << green << " " << red << "]," << '\n';
				}
				//std::cout << std::endl;
				outputFile << std::endl << '\n';

			}
		}
		else if (cv_img.channels() == 4) {
			for (int y = 0; y < cv_img.cols; y++) {
				for (int x = 0; x < cv_img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Vec4b pixel = cv_img.at<cv::Vec4b>(x, y);

					cv::Scalar qr_pixel = qr_img.at<uchar>(x, y);
					//std::cout << pixel.val[0] << ",";
					//outputFile << qr_pixel.val[0] << '\n';
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];
					int alpha = pixel.val[3];
					if (qr_pixel.val[0] == 0) {
						pixel.val[0] = 0;
					//	pixel.val[1] = 0;
					//	pixel.val[2] = 0;
					}
					else{
						pixel.val[0] = 255;
					//	pixel.val[1] = 255;
					//	pixel.val[2] = 255;
					}
					

					

					//std::cout << "[" << blue << " " << green << " " << red << "],";

					cv_img.at<cv::Vec4b>(x, y) = pixel;

					outputFile << "[" << blue << " " << green << " " << red << " " << alpha << "]," << '\n';
				}
				//std::cout << std::endl;
				outputFile << std::endl << '\n';

			}
		}
		else {
			std::cout << "this is not a single channel image" << std::endl;
		}

		imwrite("lena_stogo.png", cv_img);
		// Close the file.
		outputFile.close();

		//cv::waitKey(0);
		return 0;


	}

public:
	int readQRCodePixel() {
		cv::Mat img ,new_img;

		img = cv::imread("one_lemma_pic_2.png", CV_LOAD_IMAGE_UNCHANGED);
		//img = cv::imread("mario_l_bw.png", CV_LOAD_IMAGE_UNCHANGED);

		//
	//	cv::Mat im_gray = cv::imread("pic.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	//	cv::Mat img_bw = im_gray > 128;
	//	imwrite("pic_gs.png", img_bw);

		if (img.empty()) {
			std::cout << "Error" << std::endl;
			return -1;
		}

		//cv::namedWindow("New_image", CV_WINDOW_NORMAL);
		//imshow("New_image", img);
		std::ofstream outputFile;
		outputFile.open("b.txt");



		// print number of channels in image
		//std::cout << "image channels: " << img.channels() << std::endl;
		//std::cout << "Pixel value: " << std::endl;
		outputFile << "image channels: " << img.channels() << '\n';
		outputFile << "Y: " << img.cols << '\n';
		outputFile << "X " << img.rows << '\n';
		outputFile << "Pixel value: " << '\n';

		// check if image is a single channel
		if (img.channels() == 1) {
			for (int y = 0; y < img.cols; y++) {
				for (int x = 0; x < img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Scalar pixel = img.at<uchar>(x, y);
					if (pixel.val[0] != 0) {
						img.at<uchar>(x, y) = 255;
						//	pixel.val[1] = 0;
						//	pixel.val[2] = 0;
					}
					
					//img.at<uchar>(x, y) = pixel;
					//std::cout << pixel.val[0] << ",";
					outputFile << pixel.val[0] << '\n';
				}
				std::cout << std::endl << '\n';
			}
		}
		else if (img.channels() == 3) {
			for (int y = 0; y < img.cols; y++) {
				for (int x = 0; x < img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Vec3b pixel = img.at<cv::Vec3b>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];

					//std::cout << "[" << blue << " " << green << " " << red << "],";
					outputFile << "[" << blue << " " << green << " " << red << "]," << '\n';
				}
				//std::cout << std::endl;
				outputFile << std::endl << '\n';

			}
		}
		else if (img.channels() == 4) {
			for (int y = 0; y < img.cols; y++) {
				for (int x = 0; x < img.rows; x++) {
					outputFile << "[" << y << " , " << x << "]";
					cv::Vec4b pixel = img.at<cv::Vec4b>(x, y);
				//	cv::Scalar new_pixel = new_img.at<uchar>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];
					int alpha = pixel.val[3];
				//	new_img.at<uchar>(x, y) = blue;
					//std::cout << "[" << blue << " " << green << " " << red << "],";
					outputFile << "[" << blue << " " << green << " " << red << " " << alpha << "]," << '\n';
				}
				//std::cout << std::endl;
				outputFile << std::endl << '\n';

			}
		}
		else {
			std::cout << "this is not a single channel image" << std::endl;
		}

		imwrite("qr_sxtraxt_2.png", img);

		// Close the file.
		outputFile.close();

		//cv::waitKey(0);
		return 0;


	}
public:
	int readFile() {
	
	cv::Mat colorImage = cv::imread("mario.png");

    // First convert the image to grayscale.
   // Mat grayImage;
   // cvtColor(colorImage, grayImage, CV_RGB2GRAY);

    // Then apply thresholding to make it binary.
   // Mat binaryImage(grayImage.size(), grayImage.type());
    //threshold(grayImage, binaryImage, 128, 255, CV_THRESH_BINARY);

    // Open the file in write mode.
    std :: ofstream outputFile;
    outputFile.open("MyFile.txt");

    // Iterate through pixels.
    for (int r = 0; r < colorImage.rows; r++)
    {
        for (int c = 0; c < colorImage.cols; c++)
        {
            int pixel = colorImage.at<uchar>(r,c);

            outputFile << pixel << '\t';
        }
        outputFile << std::endl;
    }

    // Close the file.
    outputFile.close();
    return 0;
	}

public:
	int decodeFrames() {

		// Create a VideoCapture object and open the input file
		cv::VideoCapture cap("F:/MyVideo1.avi");

		// Check if camera opened successfully
		if (!cap.isOpened()) {
			return -1;
		}

		double count = cap.get(CV_CAP_PROP_FRAME_COUNT);
		int i = 0;
		while (1) {

			cv::Mat frame;

			
			// Capture frame-by-frame
			cap >> frame;

			// If the frame is empty, break immediately
			if (frame.empty())
				break;

			int k = i++;

			if (9 < k && k < 12) {
				std::string msg = LSB_Frame_decoder(frame);
				imshow(msg, frame);
				//
				//std::string filePath = "F://frames/" + std::to_string(static_cast<long long>(i)) + ".png";
				//cv::imwrite(filePath, frame);
			}
			// Display the resulting frame
			//imshow("Frame" , frame);

			// Press  ESC on keyboard to exit

			char c =(char)cv::waitKey(25);
			if (c == 27)
				break;
		}

		// When everything done, release the video capture object
		cap.release();

		// Closes all the frames
		cv::destroyAllWindows(); 

		exit(0);

	}

public:
	int splitFrames() {
		//to extract
		std::vector<cv::Mat> frames;
		extract_frames("F:/MyVideo.mp4", frames);
		//to save
		//save_frames(frames, "\\myvideo_frames\\");

		return 0;
	}

	/*
	This functions opens a video fileand extracts the framesand put them into a vector of Mat(its the class for representing an img)
	*/
	int extract_frames(const std::string& videoFilePath,std::vector<cv::Mat>& frames) {

		try {
			//open the video file
			cv::VideoCapture cap(videoFilePath); // open the video file
			
			if (!cap.isOpened())  // check if we succeeded
				CV_Error(CV_StsError, "Can not open Video file");

			//
			//
			int frame_width = static_cast<int>(cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
			int frame_height = static_cast<int>(cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT));//get the height of frames of the video

			cv::Size frame_size(frame_width, frame_height);

			double frames_per_second = cap.get(CV_CAP_PROP_FPS);
			int nbFrames = cap.get(CV_CAP_PROP_FRAME_COUNT);
			
			
			int codec = cap.get(CV_CAP_PROP_FOURCC);
			//EncorderAlgo encorderAlgo;

			//int frames_per_second = 25;

			//Create and initialize the VideoWriter object 
			///cv::VideoWriter oVideoWriter("F:/MyVideo1.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
				///frames_per_second, f rame_size, true);
			cv::VideoWriter oVideoWriter("F:/MyVideo1.avi", cv::VideoWriter::fourcc('H', 'F', 'Y', 'U'),
				frames_per_second, frame_size, true);


			//cap.get(CV_CAP_PROP_FRAME_COUNT) contains the number of frames in the video;
			for (int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum++)
			{
				cv::Mat frame;
				cap >> frame; // get the next frame from video
				//frames.push_back(frame);
             	std::string filePath ="F://frames/" + std::to_string(static_cast<long long>(frameNum)) + ".png";
				cv::imwrite(filePath, frame);
				if (frameNum == 10) {
					////frame = LSB_Frame_Encoder("Test Vedio", frame);
			    	//std::string filePath ="F://frames/" + std::to_string(static_cast<long long>(frameNum)) + ".png";
			    	//cv::imwrite(filePath, frame);
				}
				
				
				
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
		cv::Mat LSB_Frame_Encoder(std::string text, cv::Mat frame) {

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

		public:
			std::string  LSB_Frame_decoder(cv::Mat frame) {
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


};
