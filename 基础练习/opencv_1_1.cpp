﻿#include<opencv2/opencv.hpp>

using namespace cv;
int main()
{

	Mat src = imread("D:/images/011.jpg");//读入图像
	imshow("输入窗口", src);//表示显示在新创建的输入窗口上，第一个参数表示窗口名称，src表示数据对象Mat 
	waitKey(0);//程序阻塞，参数表示延时时间。单位ms
	destroyAllWindows();//销毁窗口
	return 0;
}
