#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, gray_src, dst;
int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;
int type_max = 4;

void Threshold_Demo(int, void*);

int main() {

	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}

	namedWindow("输入图像", WINDOW_AUTOSIZE);
	imshow("输入图像", src);
	namedWindow("输出图像", WINDOW_AUTOSIZE);
	

	//自定义阈值滑块项
	createTrackbar("Threshold Value:", "输出图像", &threshold_value, threshold_max, Threshold_Demo);
	//自定义阈值处理方法滑块项
	createTrackbar("Type Value:", "输出图像", &type_value, type_max, Threshold_Demo);
	Threshold_Demo(0, 0);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

//滑块回调函数
void Threshold_Demo(int , void*) {
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	threshold(gray_src, dst, threshold_value, 255, type_value);
	imshow("输出图像", dst);
}