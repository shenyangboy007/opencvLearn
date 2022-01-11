#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {
	Mat src, dst, dst01;
	src = imread("d:/images/lena.png");
	if (!src.data) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü" << endl;
		return -1;
	}

	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	cvtColor(src, dst, COLOR_BGR2GRAY);
	//Ö±·½Í¼¾ùÖµ»¯
	equalizeHist(dst, dst01);

	imshow("Êä³öÍ¼Ïñ", dst01);

	vector<Mat> bgr_src;
	split(src, bgr_src);

	int histSize = 256;
	float range[] = { 0,256 };
	const float* histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_src[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges);
	calcHist(&bgr_src[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges);
	calcHist(&bgr_src[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges);

	int hist_h = 500;
	int hist_w = 512;
	int bin_w = hist_w / histSize;
	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++) {
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);

		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);

		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("Êä³öÍ¼Ïñ01", histImage);




	waitKey(0);
	destroyAllWindows();
	return 0;
}