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


void QuickDemo::pixel_Visit_Value_Dome(Mat& image) {

	int dims = image.channels(); //图像通道数
	int h = image.rows;  //图像行数
	int w = image.cols;  //图像列数

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (dims == 1) {  //单通道的灰度图像
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dims == 3) {//三通道的彩色图像
				Vec3b bgr = image.at<Vec3b>(row, col); //opencv特定的类型，获取三个颜色，三个值对应三通道
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
	namedWindow("像素值读写演示", WINDOW_FREERATIO);
	imshow("像素值读写演示", image);
}

void QuickDemo::pixel_Visit_Point_Dome(Mat& image) {

	int dims = image.channels();//图像通道数
	int h = image.rows;
	int w = image.cols;

	for (int row = 0; row < h; row++) {
		
		uchar* current_row = image.ptr<uchar>(row); //获取每行第一个像素指针

		for (int col = 0; col < w; col++) {
			if (dims == 1) {
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dims == 3) {
				*current_row++ = 255 - *current_row; //指针每做一次运算，就向后移动一位
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	namedWindow("像素指针读写演示", WINDOW_FREERATIO);
	imshow("像素指针读写演示", image);
}

void QuickDemo::operate_Demo(Mat& image) {

	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());

	dst = image - Scalar(50, 50, 50);
	imshow("减50", dst);

	m = Scalar(100, 100, 100);
	add(image, m, dst); //加法函数
	imshow("加法操作", dst);

	m = Scalar(100, 100, 100);
	subtract(image, m, dst); //减法函数
	imshow("减法操作", dst);

	m = Scalar(3, 3, 3);
	multiply(image, m, dst); //乘法函数
	imshow("乘法操作", dst);

	m = Scalar(2, 2, 2);
	divide(image, m, dst); //除法函数
	imshow("除法法操作", dst);

	int dims = image.channels();
	int h = image.rows;
	int w = image.cols;

	m = Scalar(200, 200, 200);
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			Vec3b p1 = image.at<Vec3b>(row, col);
			Vec3b p2 = m.at<Vec3b>(row, col);
			//saturate_cast函数限制取值范围0~255
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]); 
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	imshow("底层实现加法", dst);

}

void on_lightness(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(b, b, b);
	addWeighted(image, 1.0, m, 0, b, dst); //图像融合
	imshow("亮度&对比度调整", dst);
}

void on_contrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image, contrast, m, 0.0, 0, dst); 
	imshow("亮度&对比度调整", dst);
}

void QuickDemo::tracking_Bar_Dome(Mat& image) {
	namedWindow("亮度&对比度调整", WINDOW_AUTOSIZE);
	int lightness = 50;
	int max_value = 100;
	int contrast_value = 100;
	createTrackbar("Value Bar:", "亮度&对比度调整", &lightness, max_value, on_lightness, (void*)(&image)); //滑块调节函数
	createTrackbar("Contras Bar:", "亮度&对比度调整", &contrast_value, 200, on_contrast, (void*)(&image));
	on_lightness(50, &image);
}