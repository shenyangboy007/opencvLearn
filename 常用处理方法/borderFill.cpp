#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src,dst01,dst02,dst03,dst04;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü" << endl;
		return -1;
	}

	int top = (int)(0.1 * src.rows);
	int bottom = (int)(0.1 * src.rows);
	int left = (int)(0.1 * src.cols);
	int right = (int)(0.1 * src.cols);

	RNG rng(12345);
	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	
	//Ä¬ÈÏÌî³ä±ß½ç(¾µÏñ)
	copyMakeBorder(src, dst01, top, bottom, left, right, BORDER_DEFAULT, color);
	imshow("Êä³öÍ¼Ïñ01", dst01);

	//±ß½çÖØ¸´Ìæ»»Ìî³ä
	copyMakeBorder(src, dst02, top, bottom, left, right, BORDER_REPLICATE, color);
	imshow("Êä³öÍ¼Ïñ02", dst02);

	//¶Ô±ß¿òÌæ»»Ìî³ä
	copyMakeBorder(src, dst03, top, bottom, left, right, BORDER_WRAP, color);
	imshow("Êä³öÍ¼Ïñ03", dst03);

	//É«ÌõÌî³ä±ß¿ò
	copyMakeBorder(src, dst04, top, bottom, left, right, BORDER_CONSTANT, color);
	imshow("Êä³öÍ¼Ïñ04", dst04);

	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}