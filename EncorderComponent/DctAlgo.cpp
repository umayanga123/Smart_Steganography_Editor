#include <opencv2/opencv.hpp>

public enum store { STORE_FULL, STORE_ONCE, STORE_REPEAT};

class DctAlgo {

public: 
      cv::Mat encode_dct(const cv::Mat& img, const std::string& text, int mode = STORE_FULL, int channel = 0, int intensity = 30) {

		auto block_width = 8;
		auto block_height = 8;
		auto grid_width = img.cols / block_width;
		auto grid_height = img.rows / block_height;

		auto i = 0;
		auto size = text.length() * 8;

		cv::Mat imgfp;
		img.convertTo(imgfp, CV_32F);

		std::vector<cv::Mat> planes;
		split(imgfp, planes);

		for (int x = 1; x < grid_width; x++)
		{
			for (int y = 1; y < grid_height; y++)
			{
				auto px = (x - 1) * block_width;
				auto py = (y - 1) * block_height;

				cv::Mat block(planes[channel],cv:: Rect(px, py, block_width, block_height));
				cv::Mat trans(cv::Size(block_width, block_height), block.type());

				dct(block, trans);

				auto a = trans.at<float>(6, 7);
				auto b = trans.at<float>(5, 1);

				if (i >= size)
				{
					if (mode == STORE_ONCE)
					{
						break;
					}
					else if (mode == STORE_REPEAT)
					{
						i = 0;
					}
				}

				auto val = 0;
				if (i < size)
				{
					val = (text[i / 8] & 1 << i % 8) >> i % 8;
					i++;
				}

				if (val == 0)
				{
					if (a > b)
					{
						cv::swap(a, b);
					}
				}
				else
				{
					if (a < b)
					{
						cv::swap(a, b);
					}
				}

				if (a > b)
				{
					auto d = (intensity - (a - b)) / 2;
					a = a + d;
					b = b - d;
				}
				else
				{
					auto d = (intensity - (b - a)) / 2;
					a = a - d;
					b = b + d;
				}

				trans.at<float>(6, 7) = a;
				trans.at<float>(5, 1) = b;

				cv::Mat stego(cv::Size(block_width, block_height), block.type());

				idct(trans, stego);

				stego.copyTo(planes[channel](cv::Rect(px, py, block_width, block_height)));
			}

			if (i >= size && mode == STORE_ONCE)
			{
				break;
			}
		}

		cv::Mat mergedfp;
		merge(planes, mergedfp);

		cv::Mat merged;
		mergedfp.convertTo(merged, CV_8U);

		return merged;
	}


	/*!
	 * Uses discrete cosine transformation to recover data hidden in the coefficients of an image.
	 *
	 * \param img Input image with hidden data.
	 * \param channel Channel to manipulate.
	 *
	 * \return Hidden data extracted form image.
	 */
public:
	std::string decode_dct(const cv::Mat& img, int channel = 0)
	{
		//using namespace cv;
		//using namespace std;

		auto block_width = 8;
		auto block_height = 8;
		auto grid_width = img.cols / block_width;
		auto grid_height = img.rows / block_height;

		auto i = 0;
		std::string bits(grid_width * grid_height / 8, 0);

		cv::Mat imgfp;
		img.convertTo(imgfp, CV_32F);

		std::vector<cv::Mat> planes;
		split(imgfp, planes);

		for (int x = 1; x < grid_width; x++)
		{
			for (int y = 1; y < grid_height; y++)
			{
				auto px = (x - 1) * block_width;
				auto py = (y - 1) * block_height;

				cv::Mat block(planes[channel],cv:: Rect(px, py, block_width, block_height));
				cv::Mat trans(cv::Size(block_width, block_height), block.type());

				dct(block, trans);

				auto a = trans.at<float>(6, 7);
				auto b = trans.at<float>(5, 1);

				if (a > b)
				{
					bits[i / 8] |= 1 << i % 8;
				}

				i++;
			}
		}

		return bits;
	}


};