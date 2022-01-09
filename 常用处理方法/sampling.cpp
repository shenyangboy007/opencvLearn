#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst_up,dst_dowm;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	namedWindow("����ͼ��",WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);

	//�ϲ�������
	pyrUp(src, dst_up, Size(src.cols * 2, src.rows * 2));
	imshow("�ϲ������ͼ��", dst_up);

	//����������
	pyrDown(src, dst_dowm,Size(src.cols / 2, src.rows / 2));
	imshow("�²������ͼ��", dst_dowm);


	//��˹��ͬ DOG
	Mat gray, g1, g2, dogImg;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, g1, Size(3, 3), 0, 0);
	GaussianBlur(g1, g2, Size(3, 3), 0, 0);
	subtract(g1, g2, dogImg,Mat());

	//��һ����ʾ
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);
	imshow("��˹��ͬ���ͼ��", dogImg);

	waitKey(0);
	destroyAllWindows();
	return 0;
}