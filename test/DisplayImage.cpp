#include "test.hpp"
// 显示图像
void testDisplayImage() {

    const char* imageFileName = "../images/children.jpg";
    // 读取图像
    Mat image = imread(imageFileName, 1);
    // 读取失败
    if (!image.data)
    {
        printf("No image data! \n");
        return;
    }
    // 创建命名窗口
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    // 在指定名称的窗口中显示图像
    imshow("Display Image", image);

    waitKey(0);
}

