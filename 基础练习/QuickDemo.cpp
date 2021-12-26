#include<quickopencv.h>
#include<string.h>

void QuickDemo::colorSpace_Demo(Mat& image) {
	Mat gray,hsv;

	cvtColor(image,hsv, COLOR_BGR2HSV);//ͼ��ת������ RGB ת�� HSV
	cvtColor(image,gray, COLOR_BGR2GRAY);//ͼ��ת������ RGB ת�� GRAY

	imshow("hvs", hsv);
	imshow("gray", gray);

	imwrite("D:/images/21021122201.jpg", hsv); //ͼƬ���溯��
	imwrite("D:/images/21021122202.jpg", gray);

}


void QuickDemo::mat_Creation_Demo(Mat& image) {
	Mat m1, m2;
	m1 = image.clone();
	image.copyTo(m2);

	//����400*400����ͨ��ͼ��
	//ones&zeros�ǳ�ʼ���ķ��� Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3);
	Mat m3 = Mat::ones(Size(400, 400), CV_8UC3);//������ͨ������ֵ  ,��ͨ����ֵ���� m3 = 127;

	//m3��ʼΪ��ɫ
	//���ݵĿ�Ⱥͳ�������ͨ���������ġ�
	//std::cout << "width:"<<m3.cols<<"height"<< m3.rows <<"channels"<<m3.channels()<< std::endl;
	//�����鿴��ȣ��߶���ͨ������
	/*std::cout << m3 << std::endl;*/
	m3 = Scalar(0, 255, 0);

	//m4 = m3
	//��ֵM4����M3 M4�ı���,M3Ҳ�ı��ˣ�û�в����µ�����(M4��M3ͬ��)
	Mat m4 = m3.clone();

	//M4ΪM3�Ŀ�¡��M3����ԭ������ɫ������ı䡣(M4��M3��ͬ�壬�����Ǹ��Ե���ɫ)
	//m3.copyTo(m4);//��M3��ֵ��M4,�ı�m4����ɫΪ��ɫ ,m3Ҳ���ı�,������Mat m4 = m3.clone();
	//m4 = m3;//��M3��ֵ��M4,�ı�m4����ɫΪ��ɫ ,m3Ҳ�ı�
	m4 = Scalar(0, 255, 255);

	imshow("ͼ��m3", m3);
	imshow("ͼ��m4", m4);

	imwrite("D:/images/21021122203.jpg", m3);
	imwrite("D:/images/21021122204.jpg", m4);

}


void QuickDemo::pixel_Visit_Value_Dome(Mat& image) {

	int dims = image.channels(); //ͼ��ͨ����
	int h = image.rows;  //ͼ������
	int w = image.cols;  //ͼ������

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (dims == 1) {  //��ͨ���ĻҶ�ͼ��
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dims == 3) {//��ͨ���Ĳ�ɫͼ��
				Vec3b bgr = image.at<Vec3b>(row, col); //opencv�ض������ͣ���ȡ������ɫ������ֵ��Ӧ��ͨ��
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
	namedWindow("����ֵ��д��ʾ", WINDOW_FREERATIO);
	imshow("����ֵ��д��ʾ", image);
}

void QuickDemo::pixel_Visit_Point_Dome(Mat& image) {

	int dims = image.channels();//ͼ��ͨ����
	int h = image.rows;
	int w = image.cols;

	for (int row = 0; row < h; row++) {
		
		uchar* current_row = image.ptr<uchar>(row); //��ȡÿ�е�һ������ָ��

		for (int col = 0; col < w; col++) {
			if (dims == 1) {
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dims == 3) {
				*current_row++ = 255 - *current_row; //ָ��ÿ��һ�����㣬������ƶ�һλ
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	namedWindow("����ָ���д��ʾ", WINDOW_FREERATIO);
	imshow("����ָ���д��ʾ", image);
}

void QuickDemo::operate_Demo(Mat& image) {

	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());

	dst = image - Scalar(50, 50, 50);
	imshow("��50", dst);

	m = Scalar(100, 100, 100);
	add(image, m, dst); //�ӷ�����
	imshow("�ӷ�����", dst);

	m = Scalar(100, 100, 100);
	subtract(image, m, dst); //��������
	imshow("��������", dst);

	m = Scalar(3, 3, 3);
	multiply(image, m, dst); //�˷�����
	imshow("�˷�����", dst);

	m = Scalar(2, 2, 2);
	divide(image, m, dst); //��������
	imshow("����������", dst);

	int dims = image.channels();
	int h = image.rows;
	int w = image.cols;

	m = Scalar(200, 200, 200);
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			Vec3b p1 = image.at<Vec3b>(row, col);
			Vec3b p2 = m.at<Vec3b>(row, col);
			//saturate_cast��������ȡֵ��Χ0~255
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]); 
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	imshow("�ײ�ʵ�ּӷ�", dst);

}

void on_lightness(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(b, b, b);
	addWeighted(image, 1.0, m, 0, b, dst); //ͼ���ں�
	imshow("����&�Աȶȵ���", dst);
}

void on_contrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image, contrast, m, 0.0, 0, dst); 
	imshow("����&�Աȶȵ���", dst);
}

void QuickDemo::tracking_Bar_Dome(Mat& image) {
	namedWindow("����&�Աȶȵ���", WINDOW_AUTOSIZE);
	int lightness = 50;
	int max_value = 100;
	int contrast_value = 100;
	createTrackbar("Value Bar:", "����&�Աȶȵ���", &lightness, max_value, on_lightness, (void*)(&image)); //������ں���
	createTrackbar("Contras Bar:", "����&�Աȶȵ���", &contrast_value, 200, on_contrast, (void*)(&image));
	on_lightness(50, &image);
}

void QuickDemo::key_Demo(Mat& image) {
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true) {
		char c = waitKey(100); //��ȡ��������
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
		imshow("������Ӧ", dst);
		std::cout << c << std::endl;
	}
}

void QuickDemo::color_Style_Demo(Mat& image) {
	int colormap[] = {  //ɫ��ö��
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
		applyColorMap(image, dst, colormap[index % 19]); //��ɫ�˾�
		index++;
		imshow("ɫ���˾�", dst);
	}
}

void QuickDemo::bitwise_Demo(Mat& image) {
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1,LINE_8, 0);//��������
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1,LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	bitwise_and(m1, m2, dst); //�����
	bitwise_or(m1, m2, dst);  //�����
	bitwise_not(image, dst);  //�ǲ���
	bitwise_xor(m1, m2, dst);  //���
	imshow("����λ����", dst);
}

void QuickDemo::channels_Demo(Mat& image) {
	std::vector<Mat> mv;
	split(image, mv);  //ͼ��ͨ������
	Mat dst;
	mv[1] = 0;
	mv[2] = 0;
	merge(mv, dst);
	imshow("��ɫ", dst);
	int from_to[] = { 0,2,1,1,2,0 };
	mixChannels(&image, 1, &dst, 1, from_to, 3);  //ͨ�����
	imshow("ͨ�����", dst);
}

void QuickDemo::inrange_Demo(Mat& image) {
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;
	//35,43,46����ͼƬ����ɫHSVɫ�ʿռ����ֵ��ȷ��ͼƬ��ȡֵ��Сֵ
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);
	bitwise_not(mask, mask);
	imshow("mask", mask);
	image.copyTo(redback, mask);//��redback���Ƶ�mask��ͨ��mask�ںϵõ��������Ļ�����ͼ��
	imshow("roi��ȡ", redback);
}

void QuickDemo::pixel_Statistic_Demo(Mat& image) {

	double minv, maxv;
	Point minLoc, maxLoc;
	std::vector<Mat>mv;
	split(image, mv);
	for (int i = 0; i < mv.size(); i++) {
		minMaxLoc(mv[i], &minv, &maxv, &minLoc,&maxLoc, Mat());//��ͼ�����ֵ����Сֵ
		std::cout << "No.channels:" << i << "minvalue:" << minv << "maxvalue:" << maxv << std::endl;
	}
	Mat mean, stddev;
	meanStdDev(image, mean, stddev);//��ͼ��ľ�ֵ�ͷ���
	std::cout << "mean:" << mean << std::endl;
	std::cout << "stdev:" << stddev << std::endl;
	imshow("ͳ��",image);
}

void QuickDemo::drawing_Demo(Mat& image) {
	Rect rect;
	rect.x = 200;
	rect.y = 200;
	rect.width = 100;
	rect.height = 100;
	Mat bg = Mat::zeros(image.size(), image.type());
	rectangle(image, rect, Scalar(0, 0, 255), -1, 8, 0);//������
	circle(bg, Point(350, 400), 15, Scalar(0, 0, 255), 2, LINE_AA, 0);//��Բ
	Mat dst;
	RotatedRect rtt;
	rtt.center = Point(200, 200);
	rtt.size = Size(100, 200);
	rtt.angle = 0.0;
	line(bg, Point(100, 100),Point(350,400),Scalar(0, 0, 255), 8, LINE_AA, 0);//����
	ellipse(bg, rtt, Scalar(0, 0, 255), 2, 8);//����Բ
	imshow("���εĻ���", bg);
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
		line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 8, LINE_AA, 0);//����ֱ�ߺ���
		imshow("�������", canvas);
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
	imshow("����λ���", canvas);

}

Point sp(-1, -1);
Point ep(-1, -1);
Mat temp;
//���ص�����
void on_draw(int event, int x, int y, int flag, void* userdata) {
	Mat image = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {//�����������¼�
		sp.x = x;
		sp.y = y;
		std::cout << "start point" << sp << std::endl;
	}
	else if (event == EVENT_LBUTTONUP) {//�������ɿ��¼�
		ep.x = x;
		ep.y = y;
		int dx = ep.x - sp.x;
		int dy = ep.y - sp.y;
		if (dx > 0 && dy > 0) {
			Rect box(sp.x, sp.y, dx, dy);
			imshow("ROI����", image(box));
			rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
			sp.x = -1;
			sp.y = -1;
		}
	}
	else if (event == EVENT_MOUSEMOVE) {//����ƶ��¼�
		if (sp.x > 0 && sp.y > 0) {
			ep.x = x;
			ep.y = y;
			int dx = ep.x - sp.x;
			int dy = ep.y - sp.y;
			if (dx > 0 && dy > 0) {
				Rect box(sp.x, sp.y, dx, dy);
				temp.copyTo(image);
				rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
				imshow("������", image);
			}
		}
	}
}



void QuickDemo::mouse_Drawing_Demo(Mat& image) {
	namedWindow("������", WINDOW_AUTOSIZE);
	setMouseCallback("������", on_draw, (void*)(&image));
	imshow("������", image);
	temp = image.clone();
}