#include "Histogram.h"


Histogram1D::Histogram1D()
{
	histSize[0] = 256;
	hranges[0] = 0.0f;
	hranges[1] = 255.0f;
	ranges[0] = hranges; //变化范围
	channels[0] = 0;
}


Histogram1D::~Histogram1D()
{
}

MatND Histogram1D::getHistogram(const Mat& image)
{
	MatND hist;
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);//里面全是指针数组，目的是为了拓展到多维
	return hist;
}

Mat Histogram1D::getHistogramImage(const Mat& image)
{
	MatND hist = getHistogram(image);

	double maxVal;
	double minVal;

	minMaxLoc(hist, &minVal, &maxVal, 0, 0);

	Mat histImg(histSize[0], histSize[0], CV_8U, Scalar(255));

	int hpt = static_cast<int>(0.9*histSize[0]); //把直方图的最高点设置成总高度的0.9倍

	for (int h = 0; h < histSize[0]; ++h){

		float binVal = hist.at<float>(h);

		int intensity = static_cast<int>(binVal*hpt / maxVal);

		line(histImg, Point(h, histSize[0]), Point(h, histSize[0] - intensity), Scalar::all(0)); //OpenCV坐标系，原点在左上，Y轴朝下
	}

	return histImg;
}

Mat Histogram1D::applyLookUp(const Mat& image, const Mat& lookup)
{
	Mat result;

	LUT(image, lookup, result);

	return result;
}
