#include "test.hpp"

void testFileStorage() {
    // 创建文件存储对象,写入
    FileStorage fs("../data/test.yml", FileStorage::WRITE);
    // 保存整数
    int fps = 5;
    fs << "fps" << fps;
    // 创建矩阵
    Mat m1 = Mat::eye(2, 3, CV_32F);
    cout << "m1:\n" << m1 << endl;
    cout << "m1 + 1:\n" << m1 + 1 << endl;
    Mat m2 = Mat::ones(3, 2, CV_32F);
    cout << "m2:\n" << m2 << endl;
    cout << "m2 + 3:\n" << m2 + 3 << endl;

    Mat result = (m1 + 1).mul(m1 + 3); //点积
    cout << "(m1 + 1).*(m1 + 3):\n" << result << endl;
    // 以"Result_Dot"为键保存矩阵的点积
    fs << "Result_Dot" << result;
    // 以"Result_Mul"为键保存矩阵的乘积
    result = (m1 + 2) * m2;
    fs << "Result_Mul" << result;
    // 释放文件
    fs.release();

    // 创建文件存储对象，读取
    FileStorage fsr("../data/test.yml", FileStorage::READ);
    Mat r;
    // 以"Result_Dot"为键读取相应的结果矩阵
    fsr["Result_Dot"] >> r;
    cout << "Result_Dot:\n" << r << endl;
    // 以"Result_Mul"为键读取相应的结果矩阵
    fsr["Result_Mul"] >> r;
    cout << "Result_Mul:\n" << r << endl;

    fsr.release();
}