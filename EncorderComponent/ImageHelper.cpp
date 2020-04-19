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

/*image to itrogame*/
/*Convert Image To Black and White**/
public:
	int getHistograme(std::string path) {
		cv::Mat src = cv::imread(path, CV_LOAD_IMAGE_ANYCOLOR);

		if (src.empty()) {
			return -1;
		}
		std::vector<cv::Mat> bgr_planes;
		split(src, bgr_planes);
		int histSize = 256;
		float range[] = { 0, 256 }; //the upper boundary is exclusive
		const float* histRange = { range };
		bool uniform = true, accumulate = false;
		cv::Mat b_hist, g_hist, r_hist;
		calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
		calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
		calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
		int hist_w = 512, hist_h = 400;
		int bin_w = cvRound((double)hist_w / histSize);
		cv::Mat histImage(hist_h, hist_w, CV_8UC3,cv::Scalar(0, 0, 0));
		normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
		normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
		normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
		for (int i = 1; i < histSize; i++)
		{
			line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
				cv::Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
				cv::Scalar(255, 0, 0), 2, 8, 0);
			line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
				cv::Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
				cv::Scalar(0, 255, 0), 2, 8, 0);
			line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
				cv::Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
				cv::Scalar(0, 0, 255), 2, 8, 0);
		}
		imshow("Source image", src);
		imshow("calcHist Demo", histImage);
		cv::waitKey();

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
		imwrite("output/sc/decode_single_ch_code_" + path.substr(path.find_last_of("/\\") + 1), one_ch_image);


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

