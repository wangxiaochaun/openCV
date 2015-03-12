#pragma once
/*
����ģʽ�����㷨��װ����
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
	// ��ȡ������ɫ�ʾ�����ֵ�� const���γ�Ա�����������ж���1.const�����޸������ķǾ�̬���ݳ�Ա�������ͺܺõı����˳�Ա�����鲻�޸ĳ�Ա�����ĺ�����ʹ��const��2. const���εĺ������Կ�����ͬ�����������أ���const����ֻ�ܵ���const���εĳ�Ա����
	void setColorDistanceThreshold(int distance);
	int getColorDistanceThreshold() const;
	// ��ȡ������Ŀ����ɫ
	void setTargetColor(Vec3b color);
	Vec3b getTargetColor() const;
private:	
	// Private Parameter
	int miniDist;
	Vec3b target;
	Mat result;
};

