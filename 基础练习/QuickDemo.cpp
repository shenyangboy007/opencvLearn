#include<quickopencv.h>

void QuickDemo::colorSpace_Demo(Mat& image) {
	Mat gray,hsv;

	cvtColor(image,hsv, COLOR_BGR2HSV);//ͼ��ת������ RGB ת�� HSV
	cvtColor(image,gray, COLOR_BGR2GRAY);//ͼ��ת������ RGB ת�� GRAY

	imshow("hvs", hsv);
	imshow("gray", gray);

	imwrite("D:/images/21021122201.jpg", hsv); //ͼƬ���溯��
	imwrite("D:/images/21021122202.jpg", gray);

}