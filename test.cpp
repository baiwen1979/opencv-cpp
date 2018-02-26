#include <iostream>
#include <string>
#include <sstream>
// OpenCV 头文件
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

// 显示图像
void testDisplayImage() {

    Mat image;
    const char* imageFileName = "images/children.jpg";
    image = imread(imageFileName, 1 );

    if ( !image.data )
    {
        printf("No image data! \n");
        return ;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);
}

// 读写图像
void testReadWriteImage() {

}

