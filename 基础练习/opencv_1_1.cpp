#include<opencv2/opencv.hpp>
#include<quickopencv.h>

using namespace cv;
int main()
{
	Mat src = imread("D:/images/1_1.jpg");//读入图像
	imshow("输入窗口", src);//表示显示在新创建的输入窗口上，第一个参数表示窗口名称，src表示数据对象Mat 

	QuickDemo qd; //初始化实例

	qd.colorSpace_Demo(src); //调用方法

	qd.mat_Creation_Demo(src);//调用方法

	qd.pixel_Visit_Point_Dome(src);
	
	qd.pixel_Visit_Value_Dome(src);

	src = imread("D:/images/1_1.jpg");

	qd.operate_Demo(src);

	waitKey(0);//程序阻塞，参数表示延时时间。单位ms
	destroyAllWindows();//销毁窗口
	return 0;
}

