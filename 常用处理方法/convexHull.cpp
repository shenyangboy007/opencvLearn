#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, gray, dst;
int threshold_value = 100;
int threshold_max = 255;

void Threshold_Callback(int, void*);

int main() {

	src = imread("d:/images/hand.jpg");

	if (!src.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}

	namedWindow("输入图像", WINDOW_AUTOSIZE);
	namedWindow("输出图像", WINDOW_NORMAL);

	imshow("输入图像", src);

	cvtColor(src, gray, COLOR_BGR2GRAY);
	blur(gray, gray, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	imshow("输入图像处理后", src);

	createTrackbar("阈值:", "输出图像", &threshold_value, threshold_max, Threshold_Callback);
	Threshold_Callback(0, 0);


	waitKey(0);
	return 0;
}

void Threshold_Callback(int, void*) {
	Mat bin_out;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;

	threshold(gray, bin_out, threshold_value, threshold_max, THRESH_BINARY);
	//处理轮廓
	findContours(bin_out, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	//处理凸包点
	vector<vector<Point>> convexs(contours.size());
	for (size_t i = 0; i < contours.size(); i++) {
		convexHull(contours[i], convexs[i]);
	}

	dst = Mat::zeros(src.size(), CV_8UC3);
	vector<Vec4i> empty(0);
	RNG rng(12345);
	for (size_t j = 0; j < contours.size(); j++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//绘制轮廓
		drawContours(dst, contours, j, color, 2, LINE_AA, hierachy, 0, Point(0, 0));
		//绘制凸包点
		drawContours(dst, convexs, j, color, 2, LINE_AA, empty, 0, Point(0, 0));
	}

	imshow("输出图像", dst);


}