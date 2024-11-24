#include <iostream>
using namespace std;
#include "circle.h"
#include "point.h"

//封装-设计案例-点和圆的关系

//判断点和圆的关系
void isInCircle(Circle &c, Point &p) {

    //计算两点之间距离的平方
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX())
        + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

    //计算半径的平方
    int rDistance = c.getR() * c.getR();

    //判断关系
    if (distance == rDistance) {
        cout << "点在圆上" << '\n';
    } else if (distance > rDistance) {
        cout << "点在圆外" << '\n';
    } else {
        cout << "点在圆内" << '\n';
    }
}

int main() {

    //创建圆
    Circle c;
    c.setR(10);

    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    //创建点
    Point p;
    p.setX(10);
    p.setY(10);

    //判断关系
    isInCircle(c, p);

    return 0;
}