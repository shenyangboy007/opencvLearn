#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat mat_01 = imread("d:/images/mat01.jpg");
	Mat mat_02 = imread("d:/images/mat02.jpg");

	if (!mat_01.data) {
		cout << "图一没有打开" << endl;
		return -1;
	}

	if (!mat_01.data) {
		cout << "图二没有打开" << endl;
		return -1;
	}

	Mat dst;
	double alpha = 0.5;

	//判断图像尺寸是否相同
	if (mat_01.size() == mat_02.size()) {

		addWeighted(mat_01, alpha, mat_02, (1.0 - alpha), 0.0, dst);//图像融合
		imshow("mat_01", mat_01);
		imshow("mat_02", mat_02);
		imshow("融合图像", dst);
	}
	else {
		cout << "图像尺寸不同不能融合"<< endl;
		return -1;
	}

	waitKey(0);
	destroyAllWindows();
	return 0;
}