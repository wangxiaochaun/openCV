#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

int main()
{
	cv::Mat image = cv::imread("group.jpg", 0);

	cv::Mat threshold;
	cv::threshold(image, threshold, 60, 255, CV_THRESH_BINARY);

	cv::imshow("Output1", threshold);

	cv::Mat eroded;
	cv::erode(threshold, eroded, cv::Mat());

	cv::imshow("Output2", eroded);

	cv::Mat dilated;
	cv::dilate(threshold, dilated, cv::Mat());

	cv::imshow("Output3", dilated);

	cv::waitKey(0);
}