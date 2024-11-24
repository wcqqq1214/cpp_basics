#include <iostream>
using namespace std;

//封装-属性和行为作为整体
const double PI = 3.14;

//设计一个圆类，求圆的周长
class Circle {
    
    //访问权限
public:
    
    //属性
    int m_r;    //半径

    //行为
    double calculateZC() {  //获取圆的周长
        return 2 * PI * m_r;
    }

};

int main() {

    //创建对象
    Circle c1;

    //给圆对象的属性赋值
    c1.m_r = 10;

    cout << "圆的周长为：" << c1.calculateZC() << '\n';

    system("pause");

    return 0;
}