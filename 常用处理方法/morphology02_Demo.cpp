#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst_open,dst_close,dst_gradient,dst_tophat,dst_blackhat;
	src = imread("d:/images/test0003.png");
	if (!src.data) {
		cout << "Í¼Ïñ¶ÁÈ¡Ê§°Ü" << endl;
		return -1;
	}
	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	Mat kernel = getStructuringElement(MORPH_RECT,Size(11, 11), Point(-1, -1));

	//ÐÎÌ¬Ñ§¿ª²Ù×÷
	morphologyEx(src, dst_open, MORPH_OPEN, kernel);
	namedWindow("¿ª²Ù×÷Êä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("¿ª²Ù×÷Êä³öÍ¼Ïñ", dst_open);

	//ÐÎÌ¬Ñ§±Õ²Ù×÷
	morphologyEx(~src, dst_close, MORPH_CLOSE, kernel);
	namedWindow("±Õ²Ù×÷Êä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("±Õ²Ù×÷Êä³öÍ¼Ïñ", dst_close);

	//ÐÎÌ¬Ñ§ÌÝ¶È²Ù×÷
	morphologyEx(src, dst_gradient, MORPH_GRADIENT, kernel);
	namedWindow("ÌÝ¶È²Ù×÷Êä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÌÝ¶È²Ù×÷Êä³öÍ¼Ïñ", dst_gradient);

	//ÐÎÌ¬Ñ§¶¥Ã±²Ù×÷
	morphologyEx(src, dst_tophat, MORPH_TOPHAT, kernel);
	namedWindow("¶¥Ã±²Ù×÷Êä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("¶¥Ã±²Ù×÷Êä³öÍ¼Ïñ", dst_tophat);

	//ÐÎÌ¬Ñ§ºÚÃ±²Ù×÷
	morphologyEx(~src, dst_blackhat, MORPH_BLACKHAT, kernel);
	namedWindow("ºÚÃ±²Ù×÷Êä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ºÚÃ±²Ù×÷Êä³öÍ¼Ïñ", dst_blackhat);

	waitKey(0);
	destroyAllWindows();
	return 0;
}