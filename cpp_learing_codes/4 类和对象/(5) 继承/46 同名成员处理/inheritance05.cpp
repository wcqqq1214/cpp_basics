#include <iostream>
using namespace std;

//继承-同名成员处理


//1. 子类对象可以直接访问到子类中的同名成员

//2. 子类对象加作用域可以访问到父类同名成员

//3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中的同名成员函数，加作用域可以访问到父类中的同名函数

class Base {

public:
    int m_A;

    Base() {
        m_A = 100;
    }

    void func() {
        cout << "Base - func()调用" << '\n';
    }

    void func(int a) {
        cout << "Base - func(int a)调用" << '\n';
    }
};

class Son: public Base {

public:
    int m_A;

    Son() {
        m_A = 200;
    }

    void func() {
        cout << "Son - func()调用" << '\n';
    }
};

//同名成员属性处理
void test01() {

    Son s;

    //访问子类同名成员  直接访问即可
    cout << "Son - m_A = " << s.m_A << '\n';

    //如果通过子类对象  访问父类同名成员  需要加作用域
    cout << "Base - m_A = " << s.Base::m_A << '\n';        
}

//同名成员函数处理
void test02() {

    Son s;

    s.func();

    s.Base::func();

    //如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名成员函数 (包括重载)
    s.Base::func(100);
}

int main() {

    test01();

    test02();

    system("pause");

    return EXIT_SUCCESS;
}