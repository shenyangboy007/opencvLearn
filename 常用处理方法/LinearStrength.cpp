#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst;
	src = imread("d:/images/xiaomaolu.jpg");
	if (!src.data) {
		cout << "Í¼ÏñÎª¿Õ" << endl;
		return -1;
	}

	//cvtColor(src, src, COLOR_BGR2GRAY);
	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	int height = src.rows;
	int width = src.cols;
	dst = Mat::zeros(src.size(), src.type());
	float alpha = 1.2;
	float beta = 30;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (src.channels() == 3) {
				float b = src.at<Vec3b>(row, col)[0];
				float g = src.at<Vec3b>(row, col)[1];
				float r = src.at<Vec3b>(row, col)[2];

				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * alpha + beta);
			}
			else if (src.channels() == 1) {
				float p = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(p * alpha + beta);
			}
		}
	}

	namedWindow("Êä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("Êä³öÍ¼Ïñ", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}