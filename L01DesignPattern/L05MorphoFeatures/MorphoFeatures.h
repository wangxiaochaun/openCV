#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

class MorphoFeatures
{
private:
	int threshold; // 用于生成二值图像的阈值
	// 角点检测中用到的结构元素
	Mat cross;
	Mat diamond;
	Mat square;
	Mat x;
public:
	MorphoFeatures() : 
		threshold(-1),
		cross(5, 5, CV_8U, Scalar(0)),
		diamond(5, 5, CV_8U, Scalar(1)),
		square(5, 5, CV_8U, Scalar(1)),
		x(5, 5, CV_8U, Scalar(0)){
		//创建十字形元素
		for (int i = 0; i < 5; ++i){
			cross.at<uchar>(2, i) = 1;
			cross.at<uchar>(i, 2) = 1;
		}
		//创建菱形元素
		diamond.at<uchar>(0, 0) = 0;
		diamond.at<uchar>(0, 1) = 0;
		diamond.at<uchar>(1, 0) = 0;
		diamond.at<uchar>(4, 4) = 0;
		diamond.at<uchar>(3, 4) = 0;
		diamond.at<uchar>(4, 3) = 0;
		diamond.at<uchar>(4, 0) = 0;
		diamond.at<uchar>(4, 1) = 0;
		diamond.at<uchar>(3, 0) = 0;
		diamond.at<uchar>(0, 4) = 0;
		diamond.at<uchar>(0, 3) = 0;
		diamond.at<uchar>(1, 4) = 0;
		// 创建X形元素
		for (int i = 0; i < 5; ++i){
			x.at<uchar>(i, i) = 1;
			x.at<uchar>(4 - i, i) = 1;
		}
	}
	~MorphoFeatures(){}

	Mat getEdages(const Mat& image){
		Mat result;
		morphologyEx(image, result, MORPH_GRADIENT, Mat());

		applyThreshold(result);

		return result;
	}

	void applyThreshold(Mat& image){
		if (threshold > 0){
			cv::threshold(image, image, threshold, 255, THRESH_BINARY);
		}
	}

	void setThreshold(int input){
		threshold = input;
	}

	Mat getCorners(const Mat& image){
		Mat result;

		//两次闭运算，闭运算=膨胀->腐蚀
		dilate(image, result, cross);
		erode(result, result, diamond);

		Mat result2;

		dilate(image, result2, x);
		erode(result2, result2, square);

		// 对两张图做差得到角点图像
		absdiff(result, result2, result);

		applyThreshold(result);

		return result;
	}

	void drawOnImage(const Mat& binary, Mat& image){
		Mat_<uchar>::const_iterator it = binary.begin<uchar>();
		Mat_<uchar>::const_iterator itend = binary.end<uchar>();

		for (int i = 0; it != itend; ++it, ++i){
			if (*it){
				cv::circle(image, Point(i%image.step, i/image.step), 5, Scalar(255, 0, 0));
			}
		}
	}
};

