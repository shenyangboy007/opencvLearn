#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü" << endl;
		return -1;
	}

	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	blur(gray, gray, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	Canny(gray, dst, 40, 120, 3, false);
	imshow("Êä³öÍ¼Ïñ", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}