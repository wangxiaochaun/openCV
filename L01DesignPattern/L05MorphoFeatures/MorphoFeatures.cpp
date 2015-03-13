#include "MorphoFeatures.h"


int main()
{
	Mat image = imread("building.jpg", 0);
	MorphoFeatures morpho;
	morpho.setThreshold(60);
	imshow("output", morpho.getEdages(image));

	Mat result = morpho.getCorners(image);
	imshow("output2", result);

	morpho.drawOnImage(result, image);
	imshow("output3", image);

	waitKey(0);
}
