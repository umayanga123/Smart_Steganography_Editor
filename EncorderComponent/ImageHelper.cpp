#include "opencv2/opencv.hpp"

/*image Related Operations*/
class ImageHelper{

/*Convert Image To Black and White**/
public:
	int convertImageToBW(std::string path) {
		cv::Mat im_gray = cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE);

		if (im_gray.empty()) {
			return -1;
		}
		cv::Mat img_bw = im_gray > 128;
		imwrite("output/bw/bw_image_" + path.substr(path.find_last_of("/\\") + 1), img_bw);
		return 0;
	}

/*Spilt Image To two Channel*/
public:
	int convertImageToChannel(std::string path) {
		cv::Mat img;
		img = cv::imread(path, CV_LOAD_IMAGE_UNCHANGED);

		if (img.empty() || img.channels() == 1) {
			return -1;
		}

		cv::Mat rgbchannel[3];
		// The actual splitting.
		split(img, rgbchannel);

		//Blue
		cv::namedWindow("Blue", CV_WINDOW_AUTOSIZE);
		imshow("Blue", rgbchannel[0]);
		imwrite("output/ch/blue_pic_" + path.substr(path.find_last_of("/\\") + 1), rgbchannel[0]);

		//Green
		cv::namedWindow("Green", CV_WINDOW_AUTOSIZE);
		imshow("Green", rgbchannel[1]);
		imwrite("output/ch/green_pic_" + path.substr(path.find_last_of("/\\") + 1), rgbchannel[1]);


		//Red
		cv::namedWindow("Red", CV_WINDOW_AUTOSIZE);
		imshow("Red", rgbchannel[2]);
		imwrite("output/ch/red_pic_" + path.substr(path.find_last_of("/\\") + 1), rgbchannel[2]);
	}

/*Read Image Data*/
public:
	int readImagePixel(std::string path) {

		cv::Mat img;
		img = cv::imread(path, CV_LOAD_IMAGE_UNCHANGED);

		if (img.empty()) {
			return -1;
		}

		std::ofstream outputFile;
		outputFile.open("output/pi/pixel_writer_" + path.substr(path.find_last_of(" / \\") + 1) +".txt");

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
					outputFile << "[" << blue << " " << green << " " << red << "]," << '\n';
				}
				outputFile << std::endl << '\n';

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
					outputFile << "[" << blue << " " << green << " " << red << " " << alpha << "]," << '\n';
				}
				outputFile << std::endl << '\n';

			}
		}
		else {
			std::cout << "this is not 1,3,4 channel image" << std::endl;
		}

		// Close the file.
		outputFile.close();

		return 0;


	}

/*put QR code inside the blue chanel*/
public:
	int encodeQRCodeWithInImage(std::string qr_path ,std::string img_path, bool isChecked) {

		cv::Mat qr_img;
		cv::Mat	cv_img;

		qr_img = cv::imread(qr_path, CV_LOAD_IMAGE_UNCHANGED);
		cv_img = cv::imread(img_path, CV_LOAD_IMAGE_UNCHANGED);

		
		// The actual splitting.
	

		//
		if (qr_img.empty() | cv_img.empty()) {
			return -1;
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
				std::cout << std::endl << '\n';
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

					//hard decode
					if(qr_pixel.val[0] != 0 && isChecked == true) {
						pixel.val[0] = 255;
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
					
					//hard decode
					if (qr_pixel.val[0] != 0 && isChecked == true) {
						pixel.val[0] = 255;
					}
					cv_img.at<cv::Vec4b>(x, y) = pixel;
				}
			}
		}
		else {
			std::cout << "this is not a single channel image" << std::endl;
		}

		cv::namedWindow("Stego_Image", CV_WINDOW_AUTOSIZE);
		imshow("Stego_Image", cv_img);
		imwrite("output/en/stego_image_pic_" + img_path.substr(img_path.find_last_of("/\\") + 1), cv_img);
		return 0;
	}


/*Decode QR code from image and print data*/
public:
	std::string decodeQRCodeFromImage(std::string path) {

		cv::Mat one_ch_image;
		cv::Mat img_bw;
		cv::Mat stgo_image = cv::imread(path, CV_LOAD_IMAGE_UNCHANGED);
		if (stgo_image.empty()) {
			return "ERROR";
		}

		cv::Mat rgbchannel[3];
		// The actual splitting.
		split(stgo_image, rgbchannel);

		//Blue channel Seperate
		cv::namedWindow("Blue_Channel_Only", CV_WINDOW_AUTOSIZE);
		one_ch_image = rgbchannel[0];
		imshow("Blue_Channel_Only", one_ch_image);

		//convert to BW
		/*if (isChecked == true) {
			one_ch_image.copyTo(img_bw);
			for (int y = 0; y < one_ch_image.cols; y++) {
				for (int x = 0; x < one_ch_image.rows; x++) {
					int value =(int)one_ch_image.at<uchar>(x, y);
					if (value != 0) {
						img_bw.at<uchar>(x, y) = 255;
					}
					else {
						img_bw.at<uchar>(x, y) = 0;
					}
				}
			}
		}
		else {*/
		img_bw = one_ch_image > 128;
		//}
		

		
		
		cv::namedWindow("QR_Code", CV_WINDOW_AUTOSIZE);
		imshow("QR_Code", img_bw);
		imwrite("output/de/decode_qr_code_" + path.substr(path.find_last_of("/\\") + 1), img_bw);

		//read Data of QR code
		//cv::Mat bbox, rectifiedImage;
		cv::QRCodeDetector qrDecoder = cv::QRCodeDetector::QRCodeDetector();
		std::string data = qrDecoder.detectAndDecode(img_bw);
		if (data.length() > 0)
		{
			return data;
		}
		else {
			return "Data Not Found";
		}
	}


};