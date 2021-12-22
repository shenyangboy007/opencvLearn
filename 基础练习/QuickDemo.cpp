#include<quickopencv.h>

void QuickDemo::colorSpace_Demo(Mat& image) {
	Mat gray,hsv;

	cvtColor(image,hsv, COLOR_BGR2HSV);//图像转换函数 RGB 转换 HSV
	cvtColor(image,gray, COLOR_BGR2GRAY);//图像转换函数 RGB 转换 GRAY

	imshow("hvs", hsv);
	imshow("gray", gray);

	imwrite("D:/images/21021122201.jpg", hsv); //图片保存函数
	imwrite("D:/images/21021122202.jpg", gray);

}


void QuickDemo::mat_Creation_Demo(Mat& image) {
	Mat m1, m2;
	m1 = image.clone();
	image.copyTo(m2);

	//创建400*400的三通道图像
	//ones&zeros是初始化的方法 Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3);
	Mat m3 = Mat::ones(Size(400, 400), CV_8UC3);//给三个通道都赋值  ,单通道赋值方法 m3 = 127;

	//m3初始为绿色
	//数据的宽度和长度是由通道数决定的。
	//std::cout << "width:"<<m3.cols<<"height"<< m3.rows <<"channels"<<m3.channels()<< std::endl;
	//用来查看宽度，高度与通道数。
	/*std::cout << m3 << std::endl;*/
	m3 = Scalar(0, 255, 0);

	//m4 = m3
	//赋值M4就是M3 M4改变了,M3也改变了，没有产生新的自我(M4与M3同体)
	Mat m4 = m3.clone();

	//M4为M3的克隆，M3还是原来的颜色，不会改变。(M4与M3不同体，各自是各自的颜色)
	//m3.copyTo(m4);//把M3赋值给M4,改变m4的颜色为黄色 ,m3也不改变,类似于Mat m4 = m3.clone();
	//m4 = m3;//把M3赋值给M4,改变m4的颜色为黄色 ,m3也改变
	m4 = Scalar(0, 255, 255);

	imshow("图像m3", m3);
	imshow("图像m4", m4);

	imwrite("D:/images/21021122203.jpg", m3);
	imwrite("D:/images/21021122204.jpg", m4);

}