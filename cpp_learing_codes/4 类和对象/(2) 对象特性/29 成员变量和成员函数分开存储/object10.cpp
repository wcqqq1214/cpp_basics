#include <iostream>
using namespace std;

//成员变量和成员函数分开存储

//只有 非静态成员变量 才属于类的对象上

class Person {

};

class Dog {

    int m_A;        //非静态成员变量    属于类的对象上
    static int m_B; //静态成员变量      不属于类的对象上

    void func01() {}        //非静态成员函数    不属于类的对象上

    static void func02() {} //静态成员函数      不属于类的对象上
};

int Dog::m_B = 0;

void test01() {

    Person p;

    //空对象占用内存空间为：1
    //C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "size of p = " << sizeof(p) << '\n';    //1
}

void test02() {

    Dog d;

    cout << "size of d = " << sizeof(d) << '\n';    //4
}

int main() {

    // test01();
    test02();

    system("pause");

    return 0;
}