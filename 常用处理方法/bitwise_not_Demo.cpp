#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{

    Mat src = imread("D:/images/age_gender.jpg");
    Mat gray_src;
    if (src.empty())
    {
        printf("could not load image");
        return -1;
    }
    //超过屏幕的图像无法显示时候调用此函数。
    namedWindow("输入窗口", WINDOW_AUTOSIZE);//创建了一个新窗口，参数1表示名称，第二个参数代表一个自由的比例
    imshow("输入窗口", src);//表示显示在新创建的输入窗口上，第一个参数表示窗口名称，src表示数据对象Mat 

    //cvtColor(src, src, COLOR_BGR2GRAY); //将彩色图像转换为灰度图

    Mat dst;
    dst.create(src.size(), src.type());

    //图像取反算法实现
    //int channels = src.channels();
    //int height = src.rows;
    //int width = src.cols;
    //for (int row = 0; row < height; row++) {
    //    for (int col = 0; col < width; col++) {
    //        if (channels == 3) {
    //            int b = src.at<Vec3b>(row, col)[0];
    //            int g = src.at<Vec3b>(row, col)[1];
    //            int r = src.at<Vec3b>(row, col)[2];
    //            dst.at<Vec3b>(row, col)[0] = 255 - b;
    //            dst.at<Vec3b>(row, col)[1] = 255 - g;
    //            dst.at<Vec3b>(row, col)[2] = 255 - r;
    //        }
    //        else if (channels == 1) {
    //            int gray = src.at<uchar>(row, col);
    //            dst.at<uchar>(row, col) = 255 - gray;
    //        }
    //    }
    //}

    bitwise_not(src, dst);
    namedWindow("输出窗口", WINDOW_AUTOSIZE);
    imshow("输出窗口", dst);

    waitKey(0);
    destroyAllWindows();
    return 0;
}