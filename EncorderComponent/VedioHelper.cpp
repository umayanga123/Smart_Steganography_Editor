#include "opencv2/opencv.hpp"

/*Vedio Related Operations*/
class VedioHelper {

/*put QR code inside  vedop the blue chanel*/
public:
	int encodeQRCodeWithInVedio(std::string qr_path, std::string img_path) {

		cv::Mat qr_img;
		qr_img = cv::imread(qr_path, CV_LOAD_IMAGE_UNCHANGED);
		
		//
		if (qr_img.empty()) {
			return -1;
		}

	
	    return 0;
	}



public:
	std::string decodeQCodeFromVedio(std::string v_path) {

		return "Error";
	}

};