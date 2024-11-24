#include <iostream>
using namespace std;

//初始化列表

//提供了初始化列表语法，用来初始化属性

//语法: 构造函数(): 属性1(值1), 属性2(值2), ... {}

class Person {

public:

    int m_A;
    int m_B;
    int m_C;
    
    //传统方式初始化
    // Person(int a, int b, int c) {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    //初始化列表初始化属性
    Person(int a, int b, int c): m_A(a), m_B(b), m_C(c) {

    }

};

void test01() {
    Person p(10, 20, 30);
    
    cout << "m_A = " << p.m_A 
        << "\nm_B = " << p.m_B 
        << "\nm_C = " << p.m_C << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}