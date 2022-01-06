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
    //������Ļ��ͼ���޷���ʾʱ����ô˺�����
    namedWindow("���봰��", WINDOW_AUTOSIZE);//������һ���´��ڣ�����1��ʾ���ƣ��ڶ�����������һ�����ɵı���
    imshow("���봰��", src);//��ʾ��ʾ���´��������봰���ϣ���һ��������ʾ�������ƣ�src��ʾ���ݶ���Mat 

    //cvtColor(src, src, COLOR_BGR2GRAY); //����ɫͼ��ת��Ϊ�Ҷ�ͼ

    Mat dst;
    dst.create(src.size(), src.type());

    //ͼ��ȡ���㷨ʵ��
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
    namedWindow("�������", WINDOW_AUTOSIZE);
    imshow("�������", dst);

    waitKey(0);
    destroyAllWindows();
    return 0;
}