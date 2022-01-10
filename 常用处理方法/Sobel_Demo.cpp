#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst01, dst02, dst03, dst_sobel, dst04, dst05, dst_scharr;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}

	namedWindow("输入图像", WINDOW_AUTOSIZE);
	imshow("输入图像", src);

	Mat gray;
	GaussianBlur(src, dst01, Size(3, 3), 0, 0);
	cvtColor(dst01, gray, COLOR_BGR2GRAY);
	imshow("高斯模糊灰度图像",gray);

	Sobel(gray, dst02, CV_16S, 1, 0);
	Sobel(gray, dst03, CV_16S, 0, 1);

	//取绝对值
	convertScaleAbs(dst02, dst02);
	convertScaleAbs(dst03, dst03);

	//图像融合
	addWeighted(dst02, 0.5, dst03, 0.5, 0, dst_sobel);
	imshow("sobel", dst_sobel);

	//opencv中sobel加强版
	Scharr(gray, dst04, CV_16S, 1, 0);
	Scharr(gray, dst05, CV_16S, 0, 1);

	convertScaleAbs(dst04, dst04);
	convertScaleAbs(dst05, dst05);

	addWeighted(dst04, 0.5, dst05, 0.5, 0, dst_scharr);
	imshow("scharr", dst_scharr);

	waitKey(0);
	destroyAllWindows();
	return 0;
}