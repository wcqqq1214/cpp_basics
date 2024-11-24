#include <iostream>
using namespace std;

//构造函数调用规则

//1. 创建一个类，C++编译器会给每个类都添加至少3个函数
//  默认构造 (空实现)
//  析构函数 (空实现)
//  拷贝构造    (值拷贝)

//2. 如果我们写了有参构造函数，编译器不再提供默认构造，依然提供拷贝构造

//3. 如果我们写了拷贝构造函数，编译器不再提供其他普通构造函数

class Person {

public:

    int m_Age;

    Person() {
        cout << "Person的默认构造函数调用" << '\n';
    }

    Person(int age) {
        m_Age = age;
        cout << "Person的有参构造函数调用" << '\n';
    }

    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "Person的拷贝构造函数调用" << '\n';
    }

    ~Person() {
        cout << "Person的析构函数调用" << '\n';
    }

};

// void test01() {

//     Person p;
//     p.m_Age = 18;

//     Person p2(p);

//     cout << "p2的年龄为: " << p2.m_Age << '\n';
// }

// void test02() {

//     Person p(28);

//     Person p2(p);
    
//     cout << "p2的年龄为: " << p2.m_Age << '\n';
// }

int main() {

    // test01();
    // test02();

    system("pause");

    return 0;
}