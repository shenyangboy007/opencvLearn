#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat test01, test02, test03;
int bins = 12;
void histBackProjection(int, void*);

int main() {

	test01 = imread("d:/images/lena.png");

	if (!test01.data && !test02.data && !test03.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}
	namedWindow("输出图像", WINDOW_NORMAL);

	cvtColor(test01, test02, COLOR_BGR2HSV);
	test03.create(test02.size(), test02.depth());
	int nchannels[] = { 0,0 };
	mixChannels(&test02, 1, &test03, 1, nchannels, 1);
	
	createTrackbar("直方图bin值", "输出图像", &bins, 150, histBackProjection);
	histBackProjection(0, 0);
	imshow("输出图像", test01);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

void histBackProjection(int, void*) {

	float range[] = { 0,180 };
	const float* histRanges = { range };
	Mat h_hist;
	calcHist(&test03, 1, 0, Mat(), h_hist, 1, &bins, &histRanges);
	normalize(h_hist, h_hist, 0, 255, NORM_MINMAX, -1, Mat());

	Mat backProTest;
	calcBackProject(&test03, 1, 0, h_hist, backProTest, &histRanges, 1);
	imshow("反向投影图像",backProTest);

	int hist_h = 400;
	int hist_w = 400;
	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	int bin_w = (hist_w / bins);
	for (int i = 1; i < bins; i++) {
		rectangle(histImage,
			Point((i - 1) * bin_w, (hist_h - cvRound(h_hist.at<float>(i - 1) * (400 / 255)))),
			Point(i * bin_w, hist_h),
			Scalar(0, 0, 255), -1);
	}
	imshow("直方图", histImage);

	return;


}