#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst_blur, dst_gaussblur, dst_median, dst_bilateral;
	src = imread("d:/images/xiaomaolu.jpg");
	if (!src.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}

	namedWindow("输入图像", WINDOW_AUTOSIZE);
	imshow("输入图像", src);

	//均值模糊
	blur(src, dst_blur, Size(13, 13), Point(-1, -1));
	namedWindow("输出图像 blur", WINDOW_AUTOSIZE);
	imshow("输出图像 blur", dst_blur);

	//高斯模糊
	GaussianBlur(src, dst_gaussblur, Size(13, 13), 13, 13);
	namedWindow("输出图像 blurgauss", WINDOW_AUTOSIZE);
	imshow("输出图像 blurgauss", dst_gaussblur);

	//中值模糊
	medianBlur(src, dst_median, 5);
	namedWindow("输出图像 blurmedian", WINDOW_AUTOSIZE);
	imshow("输出图像 blurmedian", dst_median);

	//双边模糊
	bilateralFilter(src, dst_bilateral, 13, 100, 4);
	namedWindow("输出图像 blurbilateral", WINDOW_AUTOSIZE);
	imshow("输出图像 blurbilateral", dst_median);

	//对双边模糊结果对比度增强
	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst_bilateral, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("对比度增强", resultImg);

	waitKey(0);
	destroyAllWindows();
	return 0;
}