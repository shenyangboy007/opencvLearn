#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int index = 0;
Mat src, dst, map_x, map_y;
void update_map(void);

int main() {
	src = imread("d:/images/lena.png");
	if (!src.data) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü" << endl;
		return -1;
	}

	namedWindow("ÊäÈëÍ¼Ïñ", WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", src);

	map_x.create(src.size(), CV_32FC1);
	map_y.create(src.size(), CV_32FC1);

	int c = 0;

	while (true) {
		c = waitKey(500);
		if ((char)c == 27) {
			break;
		}
		index = c % 5;
		update_map();
		remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 255, 255));
		imshow("Êä³öÍ¼Ïñ", dst);

	}
	destroyAllWindows();
	return 0;
}

void update_map(void) {
	for (int row = 0; row < src.rows; row++) {
		for (int col = 0; col < src.cols; col++) {
			switch (index){
			case 1:
				if (col > (src.cols * 0.25) && col <= (src.cols * 0.75) && row > (src.rows * 0.25) && row <= (src.rows * 0.75)) {
					map_x.at<float>(row, col) = 2 * (col - (src.cols * 0.25));
					map_y.at<float>(row, col) = 2 * (row - (src.rows * 0.25));
				}
				else {
					map_x.at<float>(row, col) = 0;
					map_y.at<float>(row, col) = 0;
				}
				break;
			case 2:
				map_x.at<float>(row, col) = (src.cols - col - 1);
				map_y.at<float>(row, col) = row;
				break;
			case 3:
				map_x.at<float>(row, col) = col;
				map_y.at<float>(row, col) = (src.rows - row - 1);
				break;
			case 4:
				map_x.at<float>(row, col) = (src.cols - col - 1);
				map_y.at<float>(row, col) = (src.rows - row - 1);
				break;
			}
		}
	}
}