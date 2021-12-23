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