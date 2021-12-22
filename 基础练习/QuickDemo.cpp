#include<quickopencv.h>

void QuickDemo::colorSpace_Demo(Mat& image) {
	Mat gray,hsv;

	cvtColor(image,hsv, COLOR_BGR2HSV);//Í¼Ïñ×ª»»º¯Êý RGB ×ª»» HSV
	cvtColor(image,gray, COLOR_BGR2GRAY);//Í¼Ïñ×ª»»º¯Êý RGB ×ª»» GRAY

	imshow("hvs", hsv);
	imshow("gray", gray);

	imwrite("D:/images/21021122201.jpg", hsv); //Í¼Æ¬±£´æº¯Êý
	imwrite("D:/images/21021122202.jpg", gray);

}