#include "ColorDetector.h"
#include <opencv2\highgui\highgui.hpp>
int main()
{
	//Create a object of the specified algrithom
	ColorDetector colorDetector;

	Mat image = imread("tiger.jpg");
	if (!image.data){
		return 0;
	}
	//Set parameters
	colorDetector.setTargetColor(Vec3b(130, 190, 230));
	imshow("result", colorDetector.process(image));

	waitKey(0);

	return 0;
}