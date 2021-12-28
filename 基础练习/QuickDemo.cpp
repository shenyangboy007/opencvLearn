#include<quickopencv.h>
#include<string.h>

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

void QuickDemo::key_Demo(Mat& image) {
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true) {
		char c = waitKey(100); //读取键盘输入
		if (c == 27) { //ESC
			break;
		}
		if (c == 49) { //1
			std::cout << "you enter key #1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == 50) { //2
			std::cout << "you enter key #2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		if (c == 51) { //3
			std::cout << "you enter key #3" << std::endl;
			dst = Scalar(50, 50, 50);
			add(image, dst, dst);
		}
		imshow("键盘响应", dst);
		std::cout << c << std::endl;
	}
}

void QuickDemo::color_Style_Demo(Mat& image) {
	int colormap[] = {  //色彩枚举
		COLORMAP_AUTUMN ,
		COLORMAP_BONE,
		COLORMAP_CIVIDIS,
		COLORMAP_DEEPGREEN,
		COLORMAP_HOT,
		COLORMAP_HSV,
		COLORMAP_INFERNO,
		COLORMAP_JET,
		COLORMAP_MAGMA,
		COLORMAP_OCEAN,
		COLORMAP_PINK,
		COLORMAP_PARULA,
		COLORMAP_RAINBOW,
		COLORMAP_SPRING,
		COLORMAP_TWILIGHT,
		COLORMAP_TURBO,
		COLORMAP_TWILIGHT,
		COLORMAP_VIRIDIS,
		COLORMAP_TWILIGHT_SHIFTED,
		COLORMAP_WINTER
	};
	Mat dst;
	int index = 0;
	while (true) {
		char c = waitKey(100);
		if (c == 27) {
			break;
		}
		if (c == 49) {
			std::cout << "you enter key #1" << std::endl;
			std::string nameString = "d:/images/20211224";
			nameString += std::to_string(index);
			nameString += ".jpg";
			imwrite(nameString, dst);
		}
		applyColorMap(image, dst, colormap[index % 19]); //彩色滤镜
		index++;
		imshow("色彩滤镜", dst);
	}
}

void QuickDemo::bitwise_Demo(Mat& image) {
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1,LINE_8, 0);//创建矩形
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1,LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	bitwise_and(m1, m2, dst); //与操作
	bitwise_or(m1, m2, dst);  //或操作
	bitwise_not(image, dst);  //非操作
	bitwise_xor(m1, m2, dst);  //异或
	imshow("像素位操作", dst);
}

void QuickDemo::channels_Demo(Mat& image) {
	std::vector<Mat> mv;
	split(image, mv);  //图像通道剥离
	Mat dst;
	mv[1] = 0;
	mv[2] = 0;
	merge(mv, dst);
	imshow("蓝色", dst);
	int from_to[] = { 0,2,1,1,2,0 };
	mixChannels(&image, 1, &dst, 1, from_to, 3);  //通道混合
	imshow("通道混合", dst);
}

void QuickDemo::inrange_Demo(Mat& image) {
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;
	//35,43,46根据图片中绿色HSV色彩空间最低值来确定图片中取值最小值
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);
	bitwise_not(mask, mask);
	imshow("mask", mask);
	image.copyTo(redback, mask);//把redback复制到mask，通过mask融合得到我们最后的换背景图像
	imshow("roi提取", redback);
}

void QuickDemo::pixel_Statistic_Demo(Mat& image) {

	double minv, maxv;
	Point minLoc, maxLoc;
	std::vector<Mat>mv;
	split(image, mv);
	for (int i = 0; i < mv.size(); i++) {
		minMaxLoc(mv[i], &minv, &maxv, &minLoc,&maxLoc, Mat());//求图像最大值和最小值
		std::cout << "No.channels:" << i << "minvalue:" << minv << "maxvalue:" << maxv << std::endl;
	}
	Mat mean, stddev;
	meanStdDev(image, mean, stddev);//求图像的均值和方差
	std::cout << "mean:" << mean << std::endl;
	std::cout << "stdev:" << stddev << std::endl;
	imshow("统计",image);
}

void QuickDemo::drawing_Demo(Mat& image) {
	Rect rect;
	rect.x = 200;
	rect.y = 200;
	rect.width = 100;
	rect.height = 100;
	Mat bg = Mat::zeros(image.size(), image.type());
	rectangle(image, rect, Scalar(0, 0, 255), -1, 8, 0);//画矩形
	circle(bg, Point(350, 400), 15, Scalar(0, 0, 255), 2, LINE_AA, 0);//画圆
	Mat dst;
	RotatedRect rtt;
	rtt.center = Point(200, 200);
	rtt.size = Size(100, 200);
	rtt.angle = 0.0;
	line(bg, Point(100, 100),Point(350,400),Scalar(0, 0, 255), 8, LINE_AA, 0);//划线
	ellipse(bg, rtt, Scalar(0, 0, 255), 2, 8);//画椭圆
	imshow("矩形的绘制", bg);
}

void QuickDemo::randow_Drawing_Demo() {
	Mat canvas = Mat::zeros(Size(512,512), CV_8UC3);
	int w = canvas.cols;
	int h = canvas.rows;
	RNG rng(12345);
	while (true) {
		int c = waitKey(10);
		if (c == 27) {
			break;
		}
		int x1 = rng.uniform(0, w);
		int y1 = rng.uniform(0, h);
		int x2 = rng.uniform(0, w);
		int y2 = rng.uniform(0, h);
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		//canvas = Scalar(0, 0, 0);
		line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 8, LINE_AA, 0);//绘制直线函数
		imshow("随机绘制", canvas);
	}
}

void QuickDemo::polyline_Drawing_Demo(Mat& image) {

	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
	Point p1(100, 100);
	Point p2(350, 100);
	Point p3(450, 280);
	Point p4(320, 450);
	Point p5(80, 400);
	std::vector<Point> pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	std::vector<std::vector<Point>>contours;
	contours.push_back(pts);
	drawContours(canvas, contours, -1, Scalar(0, 0, 255), -1);
	imshow("多边形绘制", canvas);

}

Point sp(-1, -1);
Point ep(-1, -1);
Mat temp;
//鼠标回调函数
void on_draw(int event, int x, int y, int flag, void* userdata) {
	Mat image = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {//鼠标左键按下事件
		sp.x = x;
		sp.y = y;
		std::cout << "start point" << sp << std::endl;
	}
	else if (event == EVENT_LBUTTONUP) {//鼠标左键松开事件
		ep.x = x;
		ep.y = y;
		int dx = ep.x - sp.x;
		int dy = ep.y - sp.y;
		if (dx > 0 && dy > 0) {
			Rect box(sp.x, sp.y, dx, dy);
			imshow("ROI区域", image(box));
			rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
			sp.x = -1;
			sp.y = -1;
		}
	}
	else if (event == EVENT_MOUSEMOVE) {//鼠标移动事件
		if (sp.x > 0 && sp.y > 0) {
			ep.x = x;
			ep.y = y;
			int dx = ep.x - sp.x;
			int dy = ep.y - sp.y;
			if (dx > 0 && dy > 0) {
				Rect box(sp.x, sp.y, dx, dy);
				temp.copyTo(image);
				rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
				imshow("鼠标绘制", image);
			}
		}
	}
}



void QuickDemo::mouse_Drawing_Demo(Mat& image) {
	namedWindow("鼠标绘制", WINDOW_AUTOSIZE);
	setMouseCallback("鼠标绘制", on_draw, (void*)(&image));
	imshow("鼠标绘制", image);
	temp = image.clone();
}

int QuickDemo::video_Test_Demo() {
	//如果有外接摄像头，则ID为0，内置为1，否则用0就可以表示内置摄像头
	VideoCapture cap(0);
	//判断摄像头是否打开
	if (!cap.isOpened())
	{
		return -1;
	}

	Mat myframe;
	Mat edges;

	bool stop = false;
	while (!stop)
	{
		//获取当前帧
		cap >> myframe;
		//转化为灰度图  
		cvtColor(myframe, edges, COLOR_BGR2GRAY);
		//高斯滤波器  
		GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		//Canny算子检测边缘  
		Canny(edges, edges, 0, 30, 3);
		//显示边缘  
		imshow("current frame", edges);
		if (waitKey(30) >= 0)
			stop = true;
	}
	cv::waitKey(0);
}

void QuickDemo::norm_Demo(Mat& image) {
	Mat dst;
	std::cout << image.type() << std::endl;
	image.convertTo(image, CV_32F); //图像类型转换
	std::cout << image.type() << std::endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX); //图像归一化
	std::cout << dst.type() << std::endl;
	imshow("图像的归一化",dst);
}

void QuickDemo::resize_Demo(Mat& image) {
	imshow("rawimage", image);
	Mat zoomin, zoomout;
	int h = image.rows;
	int w = image.cols;
	resize(image, zoomin, Size(w / 2, h / 2), 0, 0, INTER_LINEAR);//缩小图片
	imshow("zoomin", zoomin);
	resize(image, zoomout, Size(w * 1.5, h * 1.5), 0, 0, INTER_LINEAR);//扩大图片
	imshow("zoomout", zoomout);
}

void QuickDemo::flip_Demo(Mat& image) {
	Mat dst;
	imshow("原图", image);
	flip(image, dst, 0);
	imshow("水平翻转", dst);
	flip(image, dst, 1);
	imshow("垂直翻转", dst);
	flip(image, dst, -1);
	imshow("原点翻转", dst);
}

void QuickDemo::rotate_Demo(Mat& image) {
	Mat dst, M;
	int h = image.rows;
	int w = image.cols;
	M = getRotationMatrix2D(Point(w / 2, h / 2), 45, 1.0);
	double cos = abs(M.at<double>(0, 0));
	double sin = abs(M.at<double>(0, 1));
	int nw = cos * w + sin * h;
	int nh = sin * w + cos * h;
	M.at<double>(0, 2) += (nw / 2 - w / 2);
	M.at<double>(1, 2) += (nh / 2 - h / 2);
	warpAffine(image, dst, M, Size(nw, nh), INTER_LINEAR, 0, Scalar(0, 0, 255));
	imshow("旋转演示", dst);
}

void QuickDemo::video_Demo() {
	VideoCapture capture(0);
	Mat frame;

	while (true) {
		capture.read(frame);
		if (frame.empty()) {
			break;
		}
		int c = waitKey(100);//停顿100ms 
		if (c == 27) { //esc 退出应用程序
			break;
		}
		imshow("video", frame);
		
	}
}

void QuickDemo::video_Save_Demo() {
	VideoCapture capture("D:/images/01.mp4");
	int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);
	int count = capture.get(CAP_PROP_FRAME_COUNT);
	//fps是
	double fps = capture.get(CAP_PROP_FPS);
	std::cout << "frame width" << frame_width << std::endl;
	std::cout << "frame height" << frame_height << std::endl;
	std::cout << "frame FPS" << fps << std::endl;
	std::cout << "frame count" << count << std::endl;
	VideoWriter writer("D:/test.mp4", capture.get(CAP_PROP_FOURCC), fps, Size(frame_width, frame_height), true);

	Mat frame;
	while (true) {
		capture.read(frame);
		if (frame.empty()) {
			break;
		}
		imshow("frame", frame);
		colorSpace_Demo(frame);
		writer.write(frame);

		int c = waitKey(10);
		if (c == 27) {
			break;
		}
	}

	capture.release();
	writer.release();
}

void QuickDemo::histogram_Demo(Mat& image) {
	std::vector<Mat> bgr_plane;
	split(image, bgr_plane);
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,256 };
	const float* ranges[1] = { hranges };
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;

	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);

	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < bins[0]; i++) {
		line(histImage,Point(bin_w*(i-1),hist_h - cvRound(b_hist.at<float>(i-1))), 
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
	}
	namedWindow("直方图显示", WINDOW_AUTOSIZE);
	imshow("直方图显示", histImage);
}

void QuickDemo::histogram_2d_Demo(Mat& image) {
	Mat hsv, hs_hist;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	int hbins = 30, sbins = 32;
	int hist_bins[] = { hbins,sbins };
	float h_range[] = { 0,256 };
	float s_range[] = { 0,256 };
	const float* hs_ranges[] = { h_range,s_range };
	int  hs_channels[] = { 0,1 };
	calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
	double maxVal = 0;
	minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
	int scale = 10;
	Mat hist2d_image = Mat::zeros(sbins * scale, hbins * scale, CV_8UC3);
	for (int h = 0; h < hbins; h++) {
		for (int s = 0; s < sbins; s++)
		{
			float binVal = hs_hist.at<float>(h, s);
			int intensity = cvRound(binVal * 255 / maxVal);
			rectangle(hist2d_image, Point(h * scale, s * scale),Point((h + 1) * scale - 1, (s + 1) * scale - 1),Scalar::all(intensity),-1);
		}
	}
	applyColorMap(hist2d_image, hist2d_image, COLORMAP_JET);
	imshow("H-S Histogram", hist2d_image);
}

void QuickDemo::histogram_Eq_Demo(Mat& image) {
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("灰度图像", gray);
	Mat dst;
	equalizeHist(gray, dst);
	imshow("直方图均衡图像", dst);
}

void QuickDemo::blur_Demo(Mat& image) {
	Mat dst;
	blur(image, dst, Size(20, 20), Point(-1. - 1));
	imshow("图像模糊", dst);
}

void QuickDemo::gaussian_Blur_Demo(Mat& image) {
	Mat dst;
	GaussianBlur(image, dst, Size(0,0), 15);
	imshow("高斯图像模糊", dst);
}

void QuickDemo::bifilter_Demo(Mat& image) {
	Mat dst;
	bilateralFilter(image, dst, 0, 50, 10);
	imshow("双边图像模糊", dst);
}