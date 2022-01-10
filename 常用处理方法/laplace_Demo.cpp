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

	Mat gray;
	GaussianBlur(src, gray, Size(3, 3), 0, 0);
	cvtColor(gray, gray, COLOR_BGR2GRAY);

	//������˹�˲�
	Laplacian(gray, dst01, CV_16S, 3);
	//ȥ����ֵ
	convertScaleAbs(dst01, dst01);

	//��ֵ��ȡ
	threshold(dst01, dst01, 0, 255, THRESH_OTSU | THRESH_BINARY);
	imshow("���ͼ��", dst01);

	waitKey(0);
	destroyAllWindows();
	return 0;
}