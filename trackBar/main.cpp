#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string window_name = "binaryMat";
void threshold_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	//二值化
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);
}
int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;
	srcMat = imread("test.jpg");
	if (!srcMat.data)  //判断图像是否成功载入 
	{
		cout << "图像载入失败！" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",
					window_name,
					&lowTh,
					maxTh,
					threshold_Mat,
					&gryMat);
	waitKey(0);
	return 0;
}