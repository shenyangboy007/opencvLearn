#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst, dst01;
	src = imread("d:/images/redball.png");
	if (!src.data) {
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);
	
	//��ֵģ��
	medianBlur(src, dst, 3);

	cvtColor(dst, dst01, COLOR_BGR2GRAY);

	vector<Vec3f> circles;
	//����任��ȡԲ�νṹ
	HoughCircles(dst01, circles, HOUGH_GRADIENT, 1, 10, 100, 30, 5, 50);
	src.copyTo(dst);
	for (size_t i = 0; i < circles.size(); i++) {
		Vec3f cc = circles[i];
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(0, 255, 255), 2, LINE_AA);
		circle(dst, Point(cc[0], cc[1]), 2, Scalar(0, 255, 255), 2, LINE_AA);
	}

	imshow("���ͼ��", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}