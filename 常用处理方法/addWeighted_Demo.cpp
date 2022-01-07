#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat mat_01 = imread("d:/images/mat01.jpg");
	Mat mat_02 = imread("d:/images/mat02.jpg");

	if (!mat_01.data) {
		cout << "ͼһû�д�" << endl;
		return -1;
	}

	if (!mat_01.data) {
		cout << "ͼ��û�д�" << endl;
		return -1;
	}

	Mat dst;
	double alpha = 0.5;

	//�ж�ͼ��ߴ��Ƿ���ͬ
	if (mat_01.size() == mat_02.size()) {

		addWeighted(mat_01, alpha, mat_02, (1.0 - alpha), 0.0, dst);//ͼ���ں�
		imshow("mat_01", mat_01);
		imshow("mat_02", mat_02);
		imshow("�ں�ͼ��", dst);
	}
	else {
		cout << "ͼ��ߴ粻ͬ�����ں�"<< endl;
		return -1;
	}

	waitKey(0);
	destroyAllWindows();
	return 0;
}