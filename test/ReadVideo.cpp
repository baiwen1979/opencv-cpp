#include "test.hpp"

// 命令行参数
const char* params = {
    "{help h usage ? | | print this message}"
    "{@video | | Video file, if not defined try to use camera}"
};

void testReadVideo(int argc, char* argv[]) {
    // 创建命令行解析器对象
    CommandLineParser parser(argc, argv, params);
    // 显示应用程序版本信息
    parser.about("CV Test Samples v1.0.0");

    // 如果需要，显示帮助文档
    if (parser.has("help")) {
        parser.printMessage();
        return;
    }
    // 从命令行参数中获取视频文件名
    String videoFileName = parser.get<String>(0);

    // 分析命令行参数，检测参数是否正确
    if (!parser.check()) {
        parser.printErrors();
        return;
    }

    // 创建视频捕获器对象
    VideoCapture cap;
    // 如果没有指定视频文件，则打开默认摄像头
    if (videoFileName != "") {
        cap.open(videoFileName);
    }
    else {
        cap.open(0);
    }

    // 如果打开失败
    if (!cap.isOpened()) {
        cout << "Open Video Failed!";
        return;
    }

    // 创建命名窗口
    namedWindow("Video", 1);
    // 循环读取每一帧
    while (true) {
        Mat frame; // 创建视频帧
        cap >> frame; // 获取捕获的帧
        imshow("Video", frame); // 显示当前帧
        // 30毫秒内检测按键退出
        if (waitKey(30) >= 0) {
            break;
        }
    }
    // 释放视频捕获器对象
    cap.release();

}