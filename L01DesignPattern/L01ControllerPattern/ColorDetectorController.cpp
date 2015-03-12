#include "ColorDetectorController.h"

// 单例模式特点之四：单例成员变量要定义
ColorDetectorController *ColorDetectorController::singleton = 0;


ColorDetectorController::~ColorDetectorController()
{
	delete cdetect;
}


void ColorDetectorController::setColorDistanceThreshold(int distance)
{
	cdetect->setColorDistanceThreshold(distance);
}


int	 ColorDetectorController::getColorDistanceThreshold() const
{
	return cdetect->getColorDistanceThreshold();
}


void ColorDetectorController::setTargetColor(Vec3b color)
{
	cdetect->setTargetColor(color);
}


Vec3b ColorDetectorController::getTargetColor() const
{
	cdetect->getTargetColor();
}



bool ColorDetectorController::setInputImage(std::string filename)
{
	image = imread(filename);
	if (!image.data)
		return false;
	return true;
}


const Mat ColorDetectorController::getInputImage() const
{
	return image;
}


void ColorDetectorController::process()
{
	result = cdetect->process(image);
}


const Mat ColorDetectorController::getLastResult() const
{
	return result;
}


ColorDetectorController::ColorDetectorController()
{
	// init
	cdetect = new ColorDetector();
}

void ColorDetectorController::destory()
{
	if (singleton != 0){
		delete singleton;
		singleton = 0;
	}
}

ColorDetectorController* ColorDetectorController::getInstance()
{
	if (singleton == 0){
		singleton = new ColorDetectorController;
	}

	return singleton;
}
