#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main() {

	Mat src, dst;
	src = imread("D:/images/test002.png");
	if (!src.data) {
		cout << "Í¼Ïñ¶ÁÈ¡Ê§°Ü" << endl;
		return -1;
	}
	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ",src);

	//Éú³É½á¹¹ÔªËØ
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));

	//¸¯Ê´
	erode(src, dst, structureElement);
	namedWindow("erodeÊä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("erodeÊä³öÍ¼Ïñ", dst);


	//ÅòÕÍ
	dilate(src, dst, structureElement);
	namedWindow("dilateÊä³öÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("dilateÊä³öÍ¼Ïñ", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}