#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
/*
ֱ��ͼ�����࣬ר�ż��㵥ͨ���ĻҶ�ͼ�񣬱Ƚ����׸�Ϊ����3ͨ����
Ҫ�㣺 
1.����������������������������Сֵ�����ر仯��Χ��ͨ����
2.ֱ��ͼ��λ�
*/
class Histogram1D
{
private:
	int histSize[1];//�������
	float hranges[2];//�����Сֵ
	const float *ranges[1]; //�仯��Χ
	int channels[1];
public:
	Histogram1D();
	~Histogram1D();

	MatND getHistogram(const Mat& image);

	Mat getHistogramImage(const Mat& image);

	Mat applyLookUp(const Mat& image, const Mat& lookup);
};

