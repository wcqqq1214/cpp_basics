#include <iostream>
using namespace std;

//继承-多继承语法

//C++允许一个类继承多个类

//语法：class 子类: 继承方式 父类1, 继承方式 父类2, ...

//多继承可能会引发父类中有同名成员出现，需要加作用域区分 (实际开发中不建议使用多继承！)

class Base1 {

public:
    int m_A;

    Base1() {
        m_A = 100;
    }
};

class Base2 {

public:
    int m_A;

    Base2() {
        m_A = 200;
    }
};

class Son: public Base1, public Base2 {

public:
    int m_C;
    int m_D;

    Son() {
        m_C = 300;
        m_D = 400;
    }
};

void test01() {

    Son s;

    cout << "sizeof s = " << sizeof(s) << '\n'; //16

    //当父类中出现同名成员，需要加作用域区分
    cout << "Base1 - m_A = " << s.Base1::m_A << '\n';
    cout << "Base2 - m_A = " << s.Base2::m_A << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}