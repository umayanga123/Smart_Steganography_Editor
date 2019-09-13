#include <opencv2/opencv.hpp>
//#include <fstream>;

//using namespace cv;
//using namespace std;

class Test {
public:
	int A() {
		cv::Mat img = cv::imread("lena.jpg");
		cv::namedWindow("image", cv::WindowFlags::WINDOW_NORMAL);
		imshow("image", img);
		return 0;
	}
};

/*int main()
{
	Test test;
	test.A();
	waitKey(0);
}*/