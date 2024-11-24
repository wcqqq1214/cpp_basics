#include <iostream>
using namespace std;

//继承-同名静态成员处理


//静态成员和非静态成员出现同名，处理方式一致！！！

//1. 子类对象可以直接访问到子类中的同名成员

//2. 子类对象加作用域可以访问到父类同名成员


class Base {

public:

    static int m_A;

    static void func() {
        cout << "Base - static void func()" << '\n';
    }
};

int Base::m_A = 100;


class Son: public Base {

public:

    static int m_A;

    static void func() {
        cout << "Son - static void func()" << '\n';
    }
};

int Son::m_A = 200;


//同名静态成员属性处理
void test01() {

    //1. 通过对象访问
    cout << "通过对象访问" << '\n';
    Son s;
    cout << "Son - m_A = " << s.m_A << '\n';
    cout << "Base - m_A = " << s.Base::m_A << '\n';

    //2. 通过类名访问
    cout << "\n通过类名访问" << '\n';
    cout << "Son - m_A = " << Son::m_A << '\n';
    //第1个::代表通过类名方式访问   第2个::代表访问父类作用域下
    cout << "Base - m_A = " << Son::Base::m_A << '\n';
}

//同名静态成员函数处理
void test02() {

    //1. 通过对象访问
    cout << "\n通过对象访问" << '\n';
    Son s;
    s.func();
    s.Base::func();

    //2. 通过类名访问
    cout << "\n通过类名访问" << '\n';
    Son::func();
    Son::Base::func();
}


int main() {

    test01();

    test02();

    system("pause");

    return 0;
}