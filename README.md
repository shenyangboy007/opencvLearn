# opencvLearn

----------------------------------------------------------------------------------------------------------------------------------------------------------------

基础练习

opencv1_1： 图像的读入(imread函数)和显示图像(imshow函数)

QuickDemo.colorSpace方法：图像色彩空间转换(cvtColor函数)和图像保存(imwrite函数)

QuickDemo.mat_Creation_Demo方法：图像初始化(ones()函数、zeros函数)，克隆(clone()方法)和赋值(m1=m2)

QuickDemo.pixel_Visit_Point_Dome方法：使用取值的方法对图像的点像素操作

QuickDemo.pixel_Visit_Value_Dome方法：使用取指针的方法对图像的点像素操作

QuickDemo.operate_Demo方法：图像的加减乘除方法(add(),multiply(),subtract(),divide())

QuickDemo.tracking_Bar_Dome方法：通过滑块条调节图像的对比度(addWeighted(),createTrackbar())

QuickDemo.key_Demo方法：读取键盘输入项，根据不同的输入改变图像(cvtColor())

QuickDemo.color_Style_Demo方法：颜色映射(applyColorMap())

QuickDemo.bitwise_Demo方法：像素位运算(bitwise_xxx函数)

QuickDemo.channels_Demo方法：图像色彩通道剥离和融合(split(),mixChannels())

QuickDemo::inrange_Demo方法：绿色背景分辨前景，并将前景转换背景（inRange())

QuickDemo::pixel_Statistic_Demo方法：统计图像像素值信息(minMaxLoc(),meanStdDev())

QuickDemo::drawing_Demo方法：绘制几何图形(rectangle(),circle(),ellipse(),line())

QuickDemo::randow_Drawing_Demo方法：随机绘制直线(rng(),line())

QuickDemo::polyline_Drawing_Demo方法：绘制多边形(drawContours())

QuickDemo::mouse_Drawing_Demo方法：模仿画图中拖拽鼠标绘制矩形功能(setMouseCallback())

QuickDemo::norm_demo方法：归一化(normalize())

 QuickDemo::resize_demo方法：放缩图像(resize())

QuickDemo::flip_demo方法：图像翻转(flip())

QuickDemo::rotate_demo方法：图像旋转(getRotationMatrix2D(),warpAffine())

QuickDemo::video_demo方法：视频处理(VideoCapture)

QuickDemo::histogram_demo方法：图像直方图(calcHist())

QuickDemo::histogram_2d_demo方法：图像二维直方图

QuickDemo::histogram_eq_demo方法：直方图均衡化(equalizeHist())

QuickDemo::blur_demo方法：图像模糊(blur())

QuickDemo::gaussian_blur_demo方法：高斯模糊(GaussianBlur())

QuickDemo::bifilter_demo方法：双边模糊(bilateralFilter)

----------------------------------------------------------------------------------------------------------------------------------------------------------------

常用处理方法练习

filter2D_Demo：掩膜操作

Mat:Mat常用初始化方法

bitwise_not_Demo：图像取反操作

addWeighted_Demo: 图像融合操作

LinearStrength：图像亮度线性增强

blur:均值模糊，高斯模糊，中值模糊，双边模糊

morphology_Demo：腐蚀与膨胀

morphology02_Demo：形态学开操作，闭操作，梯度操作，顶帽操作，黑帽操作

sampling：上采样，降采样，高斯不同

threshold：自定义阈值处理

borderFill：边框填充处理

linearFiltering：线性滤波(Sobel算子，拉普拉斯算子)

Sobel_Demo：sobel边界提取

laplace_Demo: 拉普拉斯边界提取

canny_Demo：canny边界提取

houghLines.cpp：霍夫变换提取直线

houghCircle：霍夫变换提取圆形结构

pixMap_Demo：图像像素映射

Histogram_Demo：直方图均质化和一维直方图

CalcHist_Compare_Demo：直方图计算与比较

calcBack：直方图反向投影

matchTemplate：模版匹配方法

------------------------------------------------------------------------

opencv小练习

