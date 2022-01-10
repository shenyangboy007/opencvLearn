#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst, dst01;
	src = imread("d:/images/lines.png");
	if (!src.data) {
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);

	Canny(src, dst, 150, 200);


	vector<Vec4f> lines;
	//����任��ȡֱ��
	HoughLinesP(dst, lines, 1, CV_PI / 180.0, 10, 0, 10);

	cvtColor(dst, dst01, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); i++) {
		Vec4f hline = lines[i];
		line(dst01, Point(hline[0], hline[1]), Point(hline[2], hline[3]), Scalar(100, 0, 255), 3,LINE_AA);
	}

	imshow("���ͼ��", dst01);

	waitKey(0);
	destroyAllWindows();
	return 0;
}