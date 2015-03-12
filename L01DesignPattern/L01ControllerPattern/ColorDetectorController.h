#pragma once
#include "ColorDetector.h"
/*
控制器模式，用一个控制器，可以控制多个算法，并比较容易实现算法类之间的通信。因为这些算法类将作为控制类的成员
单例模式，保证在程序执行期间只有一个实例存在
*/
class ColorDetectorController
{
public:
	
	~ColorDetectorController();

	void setColorDistanceThreshold(int distance);
	int	 getColorDistanceThreshold() const;

	void setTargetColor(Vec3b color);
	Vec3b getTargetColor() const;

	bool setInputImage(std::string filename);
	const Mat getInputImage() const;

	void process();

	const Mat getLastResult() const;

	// 单例模式特点之四：添加访问单例实例方法
	static ColorDetectorController* getInstance();

	// 单例模式特点之三：不需要时需要删除
	static void destory();

private:
	// 单例模式特点之一：创建一个私有成员变量，保存对单个类实例的引用
	static ColorDetectorController *singleton;
	// 单例模式特点之二：构造函数私有化，防止创建额外的实例
	ColorDetectorController();

	//这里加入各种算法类
	ColorDetector *cdetect;

	Mat image;
	Mat result;
};

