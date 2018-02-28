#include "test.hpp"

void testObjectType() {
    // 向量
    Vec3b v1(1, 2, 3), v2(2, 3, 4);
    cout << "v1 = " << v1 << ", v2 = " << v2 << endl;
    cout << "v1 + v2 = " << v1 + v2 << endl;   
    cout << "v1 * 2 = " << v1 * 2 << endl;
    cout << "2 * v1 = " << 2 * v1 << endl;
    cout << "Norm of v1: " << norm(v1) << endl;
    // 标量
    Scalar s1(1, 2, 3, 4), s2(2, 3, 4, 5);
    cout << "s1 = " << s1 << endl;
    cout << "s1 * 2 = " << s1 * 2 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1 + s2 = " << s1 + s2 << endl;
    cout << "Norm of s1: " << norm(s1) << endl;
    // 点
    Point p1(100, 200), p2(300, 400);
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 - p1 = " << p2 - p1 << endl;
    cout << "p1 * 2 = " << p1 * 2 << endl;
    cout << "3 * p1 = " << 3 * p1 << endl;
    // 尺寸
    Size sz(400, 300);
    cout << "sz = " << sz << endl;
    cout << "Area of sz: " << sz.area() << endl;
    // 矩形
    Rect rect(p1, sz);
    cout << "rect = " << rect << endl;
    cout << "Height of rect: " << rect.height << endl;
    // 旋转矩形
    RotatedRect rotatedRect(p1, sz, 3.14/2);
    cout << "Angle of rotated rect: " << rotatedRect.angle << endl;
    cout << "Bounding Box: " << rotatedRect.boundingRect() << endl;

}