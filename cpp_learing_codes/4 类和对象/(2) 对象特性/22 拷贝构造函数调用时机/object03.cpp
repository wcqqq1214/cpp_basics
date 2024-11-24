#include <iostream>
using namespace std;

//拷贝构造函数调用时机

class Person {

public:
    int m_Age;

    Person() {
        cout << "Person默认构造函数调用" << '\n';
    }

    Person(int age) {
        m_Age = age;
        cout << "Person有参构造函数调用" << '\n';
    }

    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "Person拷贝构造函数调用" << '\n';
    }

    ~Person() {
        cout << "Person析构函数调用" << '\n';
    }

};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
    Person p1(20);
    Person p2(p1);

    cout << "p2的年龄为:" << p2.m_Age << '\n';
}

//2. 值传递的方式给函数参数传值
void doWork01(Person p) {

}

void test02() {
    Person p;
    doWork01(p);
}

//3. 以值传递返回局部对象
Person doWork02() {
    Person p1;
    return Person(p1);
}

void test03() {
    Person p = doWork02();  //相当于隐式转换法
}


int main() {

    // test01();
    // test02();
    test03();

    system("pause");

    return 0;
}