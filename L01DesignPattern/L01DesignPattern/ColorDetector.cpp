#include "ColorDetector.h"


ColorDetector::ColorDetector() : miniDist(100)
{
	target[0] = target[1] = target[2] = 0;
}


ColorDetector::~ColorDetector()
{
}

int ColorDetector::getDistance(const Vec3b& color) const
{
	return abs(target[0] - color[0]) + abs(target[1] - color[1]) + abs(target[2] - color[2]);
}


Mat ColorDetector::process(const Mat& image)
{
	result.create(image.rows, image.cols, CV_8U);

	Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();

	Mat_<uchar>::iterator itout = result.begin<uchar>();

	//For each pixel
	for (; it != itend; ++it, ++itout){
		//Computer each pixel with getDistance
		if (getDistance(*it) < miniDist){
			*itout = 255;
		}
		else{
			*itout = 0;
		}
	}

	return result;
}

void  ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance < 0){
		distance = 0;
	}
	miniDist = distance;
}
int ColorDetector::getColorDistanceThreshold() const
{
	return miniDist;
}

void  ColorDetector::setTargetColor(Vec3b color)
{
	target = color;
}
Vec3b  ColorDetector::getTargetColor() const
{
	return target;
}
