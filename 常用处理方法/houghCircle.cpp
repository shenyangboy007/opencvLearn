#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst, dst01;
	src = imread("d:/images/redball.png");
	if (!src.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}

	namedWindow("输入图像", WINDOW_AUTOSIZE);
	imshow("输入图像", src);
	
	//中值模糊
	medianBlur(src, dst, 3);

	cvtColor(dst, dst01, COLOR_BGR2GRAY);

	vector<Vec3f> circles;
	//霍夫变换提取圆形结构
	HoughCircles(dst01, circles, HOUGH_GRADIENT, 1, 10, 100, 30, 5, 50);
	src.copyTo(dst);
	for (size_t i = 0; i < circles.size(); i++) {
		Vec3f cc = circles[i];
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(0, 255, 255), 2, LINE_AA);
		circle(dst, Point(cc[0], cc[1]), 2, Scalar(0, 255, 255), 2, LINE_AA);
	}

	imshow("输出图像", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}