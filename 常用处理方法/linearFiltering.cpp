#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst01, dst02, dst03;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);

	cvtColor(src, src, COLOR_BGR2GRAY);

	//Sobel X����
	Mat kernel_x = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(src, dst01, -1, kernel_x, Point(-1, -1), 0.0);
	namedWindow("Sobelx�������ͼ��", WINDOW_AUTOSIZE);
	imshow("Sobelx�������ͼ��", dst01);

	//Sobel Y����
	Mat kernel_y = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	filter2D(src, dst02, -1, kernel_y, Point(-1, -1), 0.0);
	namedWindow("Sobely�������ͼ��", WINDOW_AUTOSIZE);
	imshow("Sobely�������ͼ��", dst02);

	Mat kernel_la = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	filter2D(src, dst03, -1, kernel_la, Point(-1, -1), 0.0);
	imshow("������˹���ͼ��", dst03);

	waitKey(0);
	destroyAllWindows();
	return 0;
}