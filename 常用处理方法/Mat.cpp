#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	//���캯����ʼ��
	Mat m1(200, 200, CV_8UC3, Scalar(168, 168, 168));
	imshow("m1",m1);
	//�����ʼ��
	int arrayMat[2] = {200,200};
	Mat m2(2, arrayMat, CV_8UC1, Scalar::all(168));
	imshow("m2", m2);
	//create������ʼ��
	Mat m3;
	m3.create(200, 200, CV_8UC(1));
	imshow("m3", m3);
	//��matlab������ʼ��
	Mat m_eye = Mat::eye(200, 200, CV_64F);
	imshow("m_eye", m_eye);

	Mat m_ones = Mat::ones(200, 200, CV_64F);
	imshow("m_ones", m_ones);

	Mat m_zeros = Mat::zeros(200, 200, CV_64F);
	imshow("m_zeros", m_zeros);

	//�Զ������Mat����
	Mat m4 = (Mat_<double>(3, 3) << 0, -1, 0, -1, 0, 0, 0, 0, 1);
	cout << m4 << endl;

	//��¡����������
	Mat m5 = m3.clone();
	imshow("m5", m3);

	waitKey(0);
	destroyAllWindows();
	return 0;
}
