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
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);
	namedWindow("���ͼ��", WINDOW_AUTOSIZE);
	

	//�Զ�����ֵ������
	createTrackbar("Threshold Value:", "���ͼ��", &threshold_value, threshold_max, Threshold_Demo);
	//�Զ�����ֵ������������
	createTrackbar("Type Value:", "���ͼ��", &type_value, type_max, Threshold_Demo);
	Threshold_Demo(0, 0);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

//����ص�����
void Threshold_Demo(int , void*) {
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	threshold(gray_src, dst, threshold_value, 255, type_value);
	imshow("���ͼ��", dst);
}