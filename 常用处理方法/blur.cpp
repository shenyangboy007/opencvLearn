#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst_blur, dst_gaussblur, dst_median, dst_bilateral;
	src = imread("d:/images/xiaomaolu.jpg");
	if (!src.data) {
		cout << "ͼ�����ʧ��" << endl;
		return -1;
	}

	namedWindow("����ͼ��", WINDOW_AUTOSIZE);
	imshow("����ͼ��", src);

	//��ֵģ��
	blur(src, dst_blur, Size(13, 13), Point(-1, -1));
	namedWindow("���ͼ�� blur", WINDOW_AUTOSIZE);
	imshow("���ͼ�� blur", dst_blur);

	//��˹ģ��
	GaussianBlur(src, dst_gaussblur, Size(13, 13), 13, 13);
	namedWindow("���ͼ�� blurgauss", WINDOW_AUTOSIZE);
	imshow("���ͼ�� blurgauss", dst_gaussblur);

	//��ֵģ��
	medianBlur(src, dst_median, 5);
	namedWindow("���ͼ�� blurmedian", WINDOW_AUTOSIZE);
	imshow("���ͼ�� blurmedian", dst_median);

	//˫��ģ��
	bilateralFilter(src, dst_bilateral, 13, 100, 4);
	namedWindow("���ͼ�� blurbilateral", WINDOW_AUTOSIZE);
	imshow("���ͼ�� blurbilateral", dst_median);

	//��˫��ģ������Աȶ���ǿ
	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst_bilateral, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("�Աȶ���ǿ", resultImg);

	waitKey(0);
	destroyAllWindows();
	return 0;
}