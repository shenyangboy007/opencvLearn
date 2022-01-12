#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, temp, dst;
int match_method = TM_SQDIFF;
int max_track = 5;

void MatchF(int, void*);

int main() {
	
	src = imread("D:/images/lena.png");
	//Ä£°æÍ¼Ïñ
	temp = imread("D:/images/testLena.png");

	if (!src.data||!temp.data) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü" << endl;
		return -1;
	}

	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_NORMAL);
	imshow("ÊäÈëÍ¼Ïñ", src);

	namedWindow("Êä³öÍ¼Ïñ", WINDOW_NORMAL);
	createTrackbar("Ä£°æÆ¥Åä·½·¨:", "Êä³öÍ¼Ïñ", &match_method, max_track, MatchF);
	MatchF(0, 0);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

void MatchF(int, void*) {

	int width = src.cols - temp.cols + 1;
	int height = src.rows - temp.rows + 1;
	Mat result(width, height, CV_32FC1);

	//Ä£°æÆ¥Åäº¯Êý
	matchTemplate(src, temp, result, match_method, Mat());
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	Point minLoc;
	Point maxLoc;
	double min, max;
	src.copyTo(dst);
	Point temLoc;

	//ÅÐ¶ÏÄ¿±êµã
	minMaxLoc(result, &min, &max, &minLoc, &maxLoc, Mat());
	if (match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED) {
		temLoc = minLoc;
	}
	else {
		temLoc = maxLoc;
	}

	
	rectangle(dst, Rect(temLoc.x, temLoc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2, 8);
	rectangle(result, Rect(temLoc.x, temLoc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2, 8);

	imshow("Êä³öÍ¼Ïñ",result);
	imshow("Êä³öÍ¼Ïñ01",dst);
}