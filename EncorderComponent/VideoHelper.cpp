#include "opencv2/opencv.hpp"


class VideoHelper {

public:
	int splitFrames() {

		// Create a VideoCapture object and open the input file
		/*cv::VideoCapture cap("test_vedio.mp4");

		// Check if camera opened successfully
		if (!cap.isOpened()) {
			return -1;
		}

		while (1) {

			cv::Mat frame;
			// Capture frame-by-frame
			cap >> frame;

			// If the frame is empty, break immediately
			if (frame.empty())
				break;

			// Display the resulting frame
			imshow("Frame", frame);

			// Press  ESC on keyboard to exit
			
			char c =(char)cv::waitKey(25);
			if (c == 27)
				break;
		}

		// When everything done, release the video capture object
		cap.release();

		// Closes all the frames
		cv::destroyAllWindows(); */

		//to extract
		std::vector<cv::Mat> frames;
		extract_frames("test_vedio.mp4", frames);
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
			int frames_per_second = 25;

			//Create and initialize the VideoWriter object 
			cv::VideoWriter oVideoWriter("F:/MyVideo.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
				frames_per_second, frame_size, true);

			//cap.get(CV_CAP_PROP_FRAME_COUNT) contains the number of frames in the video;
			for (int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum++)
			{
				cv::Mat frame;
				cap >> frame; // get the next frame from video
				//frames.push_back(frame);
			////	std::string filePath ="F://frames/" + std::to_string(static_cast<long long>(frameNum)) + ".png";
			////	cv::imwrite(filePath, frame);

				
				
				
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

	/*
	It saves a vector of frames into jpg images into the outputDir as 1.jpg,2.jpg etc where 1,2 etc represents the frame number
	*/
	void save_frames(std::vector<cv::Mat>& frames, const std::string& outputDir) {
		std::vector<int> compression_params;
		compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
		compression_params.push_back(100);

		for (std::vector<cv::Mat>::iterator frame = frames.begin(); frame != frames.end(); ++frame) {
			std::string filePath = outputDir +std:: to_string(static_cast<long long>(0)) + ".jpeg";
			cv::imwrite(filePath, *frame, compression_params);
		}
	}
};
