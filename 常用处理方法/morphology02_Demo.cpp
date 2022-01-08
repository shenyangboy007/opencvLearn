#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst_open,dst_close,dst_gradient,dst_tophat,dst_blackhat;
	src = imread("d:/images/test0003.png");
	if (!src.data) {
		cout << "ͼ���ȡʧ��" << endl;
		return -1;
	}
	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);

	Mat kernel = getStructuringElement(MORPH_RECT,Size(11, 11), Point(-1, -1));

	//��̬ѧ������
	morphologyEx(src, dst_open, MORPH_OPEN, kernel);
	namedWindow("���������ͼ��", WINDOW_AUTOSIZE);
	imshow("���������ͼ��", dst_open);

	//��̬ѧ�ղ���
	morphologyEx(~src, dst_close, MORPH_CLOSE, kernel);
	namedWindow("�ղ������ͼ��", WINDOW_AUTOSIZE);
	imshow("�ղ������ͼ��", dst_close);

	//��̬ѧ�ݶȲ���
	morphologyEx(src, dst_gradient, MORPH_GRADIENT, kernel);
	namedWindow("�ݶȲ������ͼ��", WINDOW_AUTOSIZE);
	imshow("�ݶȲ������ͼ��", dst_gradient);

	//��̬ѧ��ñ����
	morphologyEx(src, dst_tophat, MORPH_TOPHAT, kernel);
	namedWindow("��ñ�������ͼ��", WINDOW_AUTOSIZE);
	imshow("��ñ�������ͼ��", dst_tophat);

	//��̬ѧ��ñ����
	morphologyEx(~src, dst_blackhat, MORPH_BLACKHAT, kernel);
	namedWindow("��ñ�������ͼ��", WINDOW_AUTOSIZE);
	imshow("��ñ�������ͼ��", dst_blackhat);

	waitKey(0);
	destroyAllWindows();
	return 0;
}