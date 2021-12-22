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

	int dims = image.channels();
	int h = image.rows;
	int w = image.cols;

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (dims == 1) {
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dims == 3) {
				Vec3b bgr = image.at<Vec3b>(row, col);
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

	int dims = image.channels();
	int h = image.rows;
	int w = image.cols;

	for (int row = 0; row < h; row++) {
		
		uchar* current_row = image.ptr<uchar>(row);

		for (int col = 0; col < w; col++) {
			if (dims == 1) {
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dims == 3) {
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	namedWindow("����ָ���д��ʾ", WINDOW_FREERATIO);
	imshow("����ָ���д��ʾ", image);
}