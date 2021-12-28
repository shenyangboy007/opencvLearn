#include<opencv2/opencv.hpp>

using namespace cv;

class QuickDemo
{
	public:
		void colorSpace_Demo(Mat& image);
		void mat_Creation_Demo(Mat& image);
		void pixel_Visit_Value_Dome(Mat& image);
		void pixel_Visit_Point_Dome(Mat& image);
		void operate_Demo(Mat& image);
		void tracking_Bar_Dome(Mat& image);
		void key_Demo(Mat& image);
		void color_Style_Demo(Mat& image);
		void bitwise_Demo(Mat& image);
		void channels_Demo(Mat& image);
		void inrange_Demo(Mat& image);
		void pixel_Statistic_Demo(Mat& image);
		void drawing_Demo(Mat& image);
		void randow_Drawing_Demo();
		void polyline_Drawing_Demo(Mat& image);
		void mouse_Drawing_Demo(Mat& image);
		int video_Test_Demo();
		void norm_Demo(Mat& image);
		void resize_Demo(Mat& image);
		void flip_Demo(Mat& image);
		void rotate_Demo(Mat& image);
		void video_Demo();
		void video_Save_Demo();
		void histogram_Demo(Mat& image);
		void histogram_2d_Demo(Mat& image);
		void histogram_Eq_Demo(Mat& image);
		void blur_Demo(Mat& image);
		void gaussian_Blur_Demo(Mat& image);
		void bifilter_Demo(Mat& image);
};