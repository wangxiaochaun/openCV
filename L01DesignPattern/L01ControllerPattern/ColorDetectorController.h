#pragma once
#include "ColorDetector.h"
/*
������ģʽ����һ�������������Կ��ƶ���㷨�����Ƚ�����ʵ���㷨��֮���ͨ�š���Ϊ��Щ�㷨�ཫ��Ϊ������ĳ�Ա
����ģʽ����֤�ڳ���ִ���ڼ�ֻ��һ��ʵ������
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

	// ����ģʽ�ص�֮�ģ���ӷ��ʵ���ʵ������
	static ColorDetectorController* getInstance();

	// ����ģʽ�ص�֮��������Ҫʱ��Ҫɾ��
	static void destory();

private:
	// ����ģʽ�ص�֮һ������һ��˽�г�Ա����������Ե�����ʵ��������
	static ColorDetectorController *singleton;
	// ����ģʽ�ص�֮�������캯��˽�л�����ֹ���������ʵ��
	ColorDetectorController();

	//�����������㷨��
	ColorDetector *cdetect;

	Mat image;
	Mat result;
};

