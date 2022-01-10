#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst01, dst02, dst03;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü" << endl;
		return -1;
	}

	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	Mat gray;
	GaussianBlur(src, gray, Size(3, 3), 0, 0);
	cvtColor(gray, gray, COLOR_BGR2GRAY);

	//À­ÆÕÀ­Ë¹ÂË²¨
	Laplacian(gray, dst01, CV_16S, 3);
	//È¥¾ø¶ÔÖµ
	convertScaleAbs(dst01, dst01);

	//·§Öµ½ØÈ¡
	threshold(dst01, dst01, 0, 255, THRESH_OTSU | THRESH_BINARY);
	imshow("Êä³öÍ¼Ïñ", dst01);

	waitKey(0);
	destroyAllWindows();
	return 0;
}