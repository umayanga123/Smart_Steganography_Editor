#include <opencv2/opencv.hpp>
#include <stdlib.h>
class ImageViwer {
public:
	int showImage(std::string path) {
		cv::Mat img = cv::imread(path, cv::IMREAD_UNCHANGED);
		cv::namedWindow(path.substr(path.find_last_of("/\\") + 1), cv::WindowFlags::WINDOW_NORMAL);
		
		// Convert to grayscale getting rid of alpha channel
		//std::vector<cv::Mat> ch;
		//cv::split(img, ch);

		imshow(path.substr(path.find_last_of("/\\") + 1), img);
		return 0;
	}
};