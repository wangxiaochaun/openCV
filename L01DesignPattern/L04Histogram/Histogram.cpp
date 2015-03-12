#include "Histogram.h"


Histogram1D::Histogram1D()
{
	histSize[0] = 256;
	hranges[0] = 0.0f;
	hranges[1] = 255.0f;
	ranges[0] = hranges; //�仯��Χ
	channels[0] = 0;
}


Histogram1D::~Histogram1D()
{
}

MatND Histogram1D::getHistogram(const Mat& image)
{
	MatND hist;
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);//����ȫ��ָ�����飬Ŀ����Ϊ����չ����ά
	return hist;
}

Mat Histogram1D::getHistogramImage(const Mat& image)
{
	MatND hist = getHistogram(image);

	double maxVal;
	double minVal;

	minMaxLoc(hist, &minVal, &maxVal, 0, 0);

	Mat histImg(histSize[0], histSize[0], CV_8U, Scalar(255));

	int hpt = static_cast<int>(0.9*histSize[0]); //��ֱ��ͼ����ߵ����ó��ܸ߶ȵ�0.9��

	for (int h = 0; h < histSize[0]; ++h){

		float binVal = hist.at<float>(h);

		int intensity = static_cast<int>(binVal*hpt / maxVal);

		line(histImg, Point(h, histSize[0]), Point(h, histSize[0] - intensity), Scalar::all(0)); //OpenCV����ϵ��ԭ�������ϣ�Y�ᳯ��
	}

	return histImg;
}

Mat Histogram1D::applyLookUp(const Mat& image, const Mat& lookup)
{
	Mat result;

	LUT(image, lookup, result);

	return result;
}
