#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, dst;
int threshold_value = 100;
int threshold_max = 255;
void find_Contours(int, void*);

int main(){
	
	src = imread("D:/images/ccla_dst.png");
	if (src.empty())
	{
		printf("ÕºœÒº”‘ÿ ß∞‹£°");
		return -1;
	}
	imshow(" ‰»ÎÕºœÒ",src);

	cvtColor(src, src, COLOR_BGR2GRAY);
	namedWindow(" ‰≥ˆÕºœÒ", WINDOW_AUTOSIZE);

	createTrackbar("„–÷µ£∫", " ‰≥ˆÕºœÒ", &threshold_value, threshold_max, find_Contours);
	find_Contours(0, 0);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

void find_Contours(int, void*) {
	Mat canny_out;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	Canny(src, canny_out, threshold_value, threshold_value * 2);
	findContours(canny_out, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	imshow(" ‰≥ˆÕºœÒ", dst);
}