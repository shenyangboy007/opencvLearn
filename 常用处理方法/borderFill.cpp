#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src,dst01,dst02,dst03,dst04;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	int top = (int)(0.1 * src.rows);
	int bottom = (int)(0.1 * src.rows);
	int left = (int)(0.1 * src.cols);
	int right = (int)(0.1 * src.cols);

	RNG rng(12345);
	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	
	//Ĭ�����߽�(����)
	copyMakeBorder(src, dst01, top, bottom, left, right, BORDER_DEFAULT, color);
	imshow("���ͼ��01", dst01);

	//�߽��ظ��滻���
	copyMakeBorder(src, dst02, top, bottom, left, right, BORDER_REPLICATE, color);
	imshow("���ͼ��02", dst02);

	//�Ա߿��滻���
	copyMakeBorder(src, dst03, top, bottom, left, right, BORDER_WRAP, color);
	imshow("���ͼ��03", dst03);

	//ɫ�����߿�
	copyMakeBorder(src, dst04, top, bottom, left, right, BORDER_CONSTANT, color);
	imshow("���ͼ��04", dst04);

	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}