#pragma once
/*
策略模式，将算法封装起来
*/
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;

class ColorDetector
{
public:
	ColorDetector();
	~ColorDetector();

	int getDistance(const Vec3b& color) const;
	Mat process(const Mat& image);
	// 获取和设置色彩距离阈值， const修饰成员函数，作用有二：1.const不能修改这个类的非静态数据成员，这样就很好的保护了成员，建议不修改成员变量的函数都使用const；2. const修饰的函数可以看做是同名函数的重载，且const对象只能调用const修饰的成员函数
	void setColorDistanceThreshold(int distance);
	int getColorDistanceThreshold() const;
	// 获取和设置目标颜色
	void setTargetColor(Vec3b color);
	Vec3b getTargetColor() const;
private:	
	// Private Parameter
	int miniDist;
	Vec3b target;
	Mat result;
};

