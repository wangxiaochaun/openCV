#include "Histogram.h"
#include <iostream>

using namespace std;

int main()
{
	Mat image = imread("tiger.jpg", 0);

	Histogram1D h;

	imshow("Output", h.getHistogramImage(image));

	// 根据某一阈值，生成二值图像
	Mat thresholded;
	threshold(image, thresholded, 60, 255, THRESH_BINARY);

	imshow("Output2", thresholded);

	int dim = 256;

	Mat lookup(1, &dim, CV_8U); //C++: Mat::Mat(int ndims, const int* sizes, int type)

	for (int i = 0; i < 256; ++i){
		lookup.at<uchar>(i) = 255 - i;
	}

	imshow("Output3", h.applyLookUp(image, lookup));


	waitKey(0);
}