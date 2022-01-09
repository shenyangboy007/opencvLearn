#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst_up,dst_dowm;
	src = imread("d:/images/home.jpg");
	if (!src.data) {
		cout << "图像加载失败" << endl;
		return -1;
	}

	namedWindow("输入图像",WINDOW_AUTOSIZE);
	imshow("输入图像", src);

	//上采样处理
	pyrUp(src, dst_up, Size(src.cols * 2, src.rows * 2));
	imshow("上采样输出图像", dst_up);

	//降采样处理
	pyrDown(src, dst_dowm,Size(src.cols / 2, src.rows / 2));
	imshow("下采样输出图像", dst_dowm);


	//高斯不同 DOG
	Mat gray, g1, g2, dogImg;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, g1, Size(3, 3), 0, 0);
	GaussianBlur(g1, g2, Size(3, 3), 0, 0);
	subtract(g1, g2, dogImg,Mat());

	//归一化显示
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);
	imshow("高斯不同结果图像", dogImg);

	waitKey(0);
	destroyAllWindows();
	return 0;
}