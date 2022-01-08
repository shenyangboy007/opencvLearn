#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst;
	src = imread("D:/images/test002.png");
	if (!src.data) {
		cout << "ͼ���ȡʧ��" << endl;
		return -1;
	}
	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��",src);

	//���ɽṹԪ��
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));

	//��ʴ
	erode(src, dst, structureElement);
	namedWindow("erode���ͼ��", WINDOW_AUTOSIZE);
	imshow("erode���ͼ��", dst);


	//����
	dilate(src, dst, structureElement);
	namedWindow("dilate���ͼ��", WINDOW_AUTOSIZE);
	imshow("dilate���ͼ��", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}