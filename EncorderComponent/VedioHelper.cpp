#include "opencv2/opencv.hpp"

/*Vedio Related Operations*/
class VedioHelper {

/*put QR code inside  vedop the blue chanel*/
public:
	int encodeQRCodeWithInVedio(std::string qr_path, std::string videoFilePath) {

		cv::Mat qr_img;
		qr_img = cv::imread(qr_path, CV_LOAD_IMAGE_UNCHANGED);
		
		//
		if (qr_img.empty() || videoFilePath.empty()) {
			return -1;
		}

		try {
			//open the video file
			cv::VideoCapture cap(videoFilePath);

			if (!cap.isOpened()) {
				// check if we succeeded
				CV_Error(CV_StsError, "Can not open Video file");
			}
					
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

				
				if (frameNum %50 == 0) {
					//Algorithem
					frame = encodeQRCodeWithInImage(qr_img, frame);
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


/*put QR code inside the blue chanel*/
public:
	cv::Mat encodeQRCodeWithInImage(cv::Mat qr_path, cv::Mat img_path) {

		//
		cv::Mat qr_img = qr_path;
		cv::Mat	cv_img = img_path;

	
		//
		if (qr_img.empty() | img_path.empty()) {
			return cv_img;
		}

		//qr code should be less than image
		// check if image is a single channel
		if (cv_img.channels() == 1) {
			for (int y = 0; y < qr_img.cols; y++) {
				for (int x = 0; x < qr_img.rows; x++) {
					cv::Scalar pixel = qr_img.at<uchar>(x, y);
					if (pixel.val[0] != 0) {
						cv_img.at<uchar>(x, y) = 255;
					}
				}
			}
		}
		else if (cv_img.channels() == 3) {
			for (int y = 0; y < qr_img.cols; y++) {
				for (int x = 0; x < qr_img.rows; x++) {
					cv::Vec3b pixel = cv_img.at<cv::Vec3b>(x, y);
					cv::Scalar qr_pixel = qr_img.at<uchar>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];

					if (qr_pixel.val[0] == 0) {
						pixel.val[0] = 0;
					}
					else {
						//pixel.val[0] = 255;
					}
					cv_img.at<cv::Vec3b>(x, y) = pixel;
				}
			}
		}
		else if (cv_img.channels() == 4) {
			for (int y = 0; y < qr_img.cols; y++) {
				for (int x = 0; x < qr_img.rows; x++) {
					cv::Vec4b pixel = cv_img.at<cv::Vec4b>(x, y);
					cv::Scalar qr_pixel = qr_img.at<uchar>(x, y);
					int blue = pixel.val[0];
					int green = pixel.val[1];
					int red = pixel.val[2];
					int alpha = pixel.val[3];
					if (qr_pixel.val[0] == 0) {
						pixel.val[0] = 0;
					}
					else {
						//pixel.val[0] = 255;
					}

					cv_img.at<cv::Vec4b>(x, y) = pixel;
				}
			}
		}
		else {
			std::cout << "this is not a single channel image" << std::endl;
		}

		return cv_img;
	}


public:
	System::String^ decodeQCodeFromVedio(std::string v_path) {
		cv::VideoCapture cap(v_path);
		double frames_per_second = cap.get(CV_CAP_PROP_FPS);
		return frames_per_second.ToString();
	}

	
/* This functions opens a video fileand extracts the framesand put them into a vector of Mat(its the class for representing an img) */
public: 
	int extract_frames(const std::string& videoFilePath) {
		try {
			//open the video file
			cv::VideoCapture cap(videoFilePath); 

			// check if we succeeded
			if (!cap.isOpened()) { 
				CV_Error(CV_StsError, "Can not open Video file");
			}

			//
			int frame_width = static_cast<int>(cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
			int frame_height = static_cast<int>(cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT));//get the height of frames of the video

			cv::Size frame_size(frame_width, frame_height);

			double frames_per_second = cap.get(CV_CAP_PROP_FPS);
			// contains the number of frames in the video
			int nbFrames = cap.get(CV_CAP_PROP_FRAME_COUNT);
			int codec = cap.get(CV_CAP_PROP_FOURCC);
		
			for (int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum++)
			{
				cv::Mat frame;
				cap >> frame; 

				std::string filePath = "F://frames/" + std::to_string(static_cast<long long>(frameNum)) + ".png";
				cv::imwrite(filePath, frame);

				if (frameNum == 10) {
					//std::string filePath ="F://frames/" + std::to_string(static_cast<long long>(frameNum)) + ".png";
					//cv::imwrite(filePath, frame);
				}

				//Wait for for 10 milliseconds until any key is pressed.  
				//If the 'Esc' key is pressed, break the while loop.
				//If any other key is pressed, continue the loop 
				//If any key is not pressed within 10 milliseconds, continue the loop 
				if (cv::waitKey(10) == 27)
				{
					break;
				}
			}
		}
		catch (cv::Exception& e) {
			return -1;
		}
		return 0;
	}

/*information of vedio*/
public:
	std::string informationOfVedio(std::string v_path) {
		cv::VideoCapture cap(v_path);
		std::string frames_per_second = std::to_string(cap.get(CV_CAP_PROP_FPS));
		std::string frame_count = std::to_string( cap.get(CV_CAP_PROP_FRAME_COUNT));
		return "FPS:" + frames_per_second + "F Count:" + frame_count;
	}

};