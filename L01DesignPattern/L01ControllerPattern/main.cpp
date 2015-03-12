#include "ColorDetectorController.h"

int main()
{
	ColorDetectorController::getInstance()->setInputImage("tiger.jpg");
	ColorDetectorController::getInstance()->setTargetColor(Vec3b(130, 190, 230));
	ColorDetectorController::getInstance()->process();

	imshow("Output", ColorDetectorController::getInstance()->getLastResult());

	waitKey(0);

	return 0;
}