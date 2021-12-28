#include<opencv2/opencv.hpp>
#include<quickopencv.h>

using namespace cv;
int main()
{
	//Mat src = imread("D:/images/1_1.jpg");//读入图像
	//imshow("输入窗口", src);//表示显示在新创建的输入窗口上，第一个参数表示窗口名称，src表示数据对象Mat 

	QuickDemo qd; //初始化实例

	//qd.colorSpace_Demo(src); //调用方法

	//qd.mat_Creation_Demo(src);//调用方法

	//qd.pixel_Visit_Point_Dome(src);
	//
	//qd.pixel_Visit_Value_Dome(src);

	//src = imread("D:/images/1_1.jpg");

	//qd.operate_Demo(src);

	//src = imread("D:/images/1_1.jpg");

	//qd.tracking_Bar_Dome(src);

	//src = imread("D:/images/1_1.jpg");

	//qd.key_Demo(src);

	//Mat src = imread("D:/images/1_1.jpg");

	//qd.color_Style_Demo(src);

	//qd.bitwise_Demo(src);

	//qd.channels_Demo(src);

	Mat src = imread("D:/images/gaoyy.png");
	imshow("输入窗口", src);

	//qd.inrange_Demo(src);
	//qd.pixel_Statistic_Demo(src);
	//qd.drawing_Demo(src);

	//qd.randow_Drawing_Demo();

	//qd.polyline_Drawing_Demo(src);

	//qd.mouse_Drawing_Demo(src);
   
	//qd.norm_Demo(src);

	//qd.resize_Demo(src);

	//qd.flip_Demo(src);

	//qd.rotate_Demo(src);

	//qd.video_Demo();

	//qd.video_Save_Demo();
	
	//qd.histogram_Demo(src);

	//qd.histogram_Eq_Demo(src);

	//qd.histogram_2d_Demo(src);

	//qd.blur_Demo(src);
	
	//qd.gaussian_Blur_Demo(src);

	qd.bifilter_Demo(src);

	waitKey(0);//程序阻塞，参数表示延时时间。单位ms
	destroyAllWindows();//销毁窗口
	return 0;
}

