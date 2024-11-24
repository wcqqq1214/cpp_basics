#include <iostream>
using namespace std;

//运算符重载 —— 左移运算符重载

//作用：可以输出自定义数据类型

class Person {

    friend ostream& operator<<(ostream &cout, Person &p);

private:

    int m_A;
    int m_B;

public:

    Person(int a, int b) {
        m_A = a;
        m_B = b;
    }

};

//不会使用成员函数来重载左移运算符，因为无法实现 cout 在左侧
//只能使用全局函数重载左移运算符
// (ostream对象只能有一个)
ostream& operator<<(ostream &cout, Person &p) {  //本质  operator<<(cout, p)   简化后  cout << p

    cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
    return cout;
}

void test01() {

    Person p(10, 10);

    cout << p << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}