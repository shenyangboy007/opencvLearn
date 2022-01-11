#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

string convertToString(double d);

int main() {
	Mat test01,test02,test03;
	Mat hsvbase01, hsvbase02, hsvbase03;
	test01 = imread("d:/images/lena.png");
	test02 = imread("d:/images/sp_noise.png");
	test03 = imread("d:/images/test.png");

	if (!test01.data&& !test02.data&& !test03.data){
		cout << "图像加载失败" << endl;
		return -1;
	}

	cvtColor(test01, hsvbase01, COLOR_BGR2HSV);
	cvtColor(test02, hsvbase02, COLOR_BGR2HSV);
	cvtColor(test03, hsvbase03, COLOR_BGR2HSV);

	int h_bins = 50;
	int s_bins = 60;
	int histSize[] = { h_bins,s_bins };

	float h_ranges[] = { 0,180 };
	float s_ranges[] = { 0,256 };
	const float* ranges[] = { h_ranges,s_ranges };

	int channels[] = { 0,1 };
	MatND hist_base01, hist_base02, hist_base03;

	//直方图计算后归一化
	calcHist(&hsvbase01, 1, channels, Mat(), hist_base01, 2, histSize, ranges);
	normalize(hist_base01, hist_base01, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsvbase02, 1, channels, Mat(), hist_base02, 2, histSize, ranges);
	normalize(hist_base02, hist_base02, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsvbase03, 1, channels, Mat(), hist_base03, 2, histSize, ranges);
	normalize(hist_base03, hist_base03, 0, 1, NORM_MINMAX, -1, Mat());

	//直方图对比
	double base01 = compareHist(hist_base01, hist_base01, HISTCMP_BHATTACHARYYA);
	double base02 = compareHist(hist_base01, hist_base02, HISTCMP_BHATTACHARYYA);
	double base03 = compareHist(hist_base01, hist_base03, HISTCMP_BHATTACHARYYA);

	putText(test01, convertToString(base01), Point(50, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 2, LINE_AA);
	putText(test02, convertToString(base02), Point(50, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 2, LINE_AA);
	putText(test03, convertToString(base03), Point(50, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 2, LINE_AA);

	imshow("输入图像1", test01);
	imshow("输入图像2", test02);
	imshow("输入图像3", test03);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

//double 转 string
string convertToString(double d) {
	ostringstream os;
	if (os << d)
		return os.str();
	return "invalid conversion";
}