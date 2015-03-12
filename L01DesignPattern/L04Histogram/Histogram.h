#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
/*
直方图辅助类，专门计算单通道的灰度图像，比较容易改为计算3通道的
要点： 
1.变量，包括项的数量、像素最大最小值、像素变化范围、通道数
2.直方图如何画
*/
class Histogram1D
{
private:
	int histSize[1];//项的数量
	float hranges[2];//最大最小值
	const float *ranges[1]; //变化范围
	int channels[1];
public:
	Histogram1D();
	~Histogram1D();

	MatND getHistogram(const Mat& image);

	Mat getHistogramImage(const Mat& image);

	Mat applyLookUp(const Mat& image, const Mat& lookup);
};

