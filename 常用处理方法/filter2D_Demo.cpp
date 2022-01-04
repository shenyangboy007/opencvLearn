#include <opencv2\opencv.hpp>
#include <math.h>
#include <iostream>
using namespace cv;
int main()
{
	Mat src, dst;
	src = imread("d:/images/cv02.jpg");
	if (!src.data) {
		printf("不能打开图像");
		return -1;
	}
	namedWindow("原图像", WINDOW_AUTOSIZE);
	imshow("原图像", src);

	//图像掩膜操作的底层实现
	/*int cols = (src.cols - 1) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}*/

	//计算操作使用时间
	double t = getTickCount();
	//掩膜矩阵
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	//图像掩膜API操作
	filter2D(src, dst, src.depth(), kernel);
	double timeusing = (getTickCount() - t) / getTickFrequency();
	printf("timeusing %.9f\n", timeusing);

	namedWindow("操作后图像", WINDOW_AUTOSIZE);
	imshow("操作后图像", dst);

	waitKey(0);
	return (0);
}