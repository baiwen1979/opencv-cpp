#include "test.hpp"
// 读写图像
void testReadWriteImage() {
    const char* imageFileName = "../images/children.jpg";
    // 读取图像
    Mat colorImg = imread(imageFileName); // 默认为彩色图像
    Mat grayImg = imread(imageFileName, CV_LOAD_IMAGE_GRAYSCALE); // 灰度图像

    // 保存灰度图像
    imwrite("../images/children_gray.jpg", grayImg);

    // 最后一个像素的坐标
    int x = colorImg.cols - 1;
    int y = colorImg.rows - 1;
    // 获取彩色图像的最后一个像素的颜色值
    Vec3b colorPixel = colorImg.at<Vec3b>(x, y);
    // 输出彩色像素值（BGR）
    cout << "Color Pixel Value (B,G,R): (" << (int)colorPixel[0] << "," <<
        (int)colorPixel[1] << "," << (int)colorPixel[2] << ")" << endl;
    // 获取灰度图像的最后一个像素的灰度值
    uchar grayPixel = grayImg.at<uchar>(x, y);
    // 输出灰度像素值
    cout << "Gray Pixel Value : " << (int)grayPixel << endl; 
    
    // 显示图像
    imshow("Children BGR", colorImg);
    imshow("Children Gray", grayImg);

    // 等待按键
    waitKey(0);
}