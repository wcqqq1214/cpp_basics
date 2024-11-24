#include <iostream>
using namespace std;

//模板-类模板成员函数类外实现

//总结: 需要在加上模板参数列表


//类模板中成员函数类外实现
template<class T1, class T2>
class Person {

public:

    //成员函数类内声明
    Person(T1 name, T2 age);

    void showPerson();

    T1 m_Name;
    T2 m_Age;
};

//构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {

    this->m_Name = name;
    this->m_Age = age;
}

//成员函数类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {

    cout << "name = " << this->m_Name << '\n';
    cout << "age = " << this->m_Age << '\n';
}

void test01() {

    Person<string, int> p("Tom", 21);
    p.showPerson();
}


int main() {

    test01();
    
    system("pause");

    return 0;
}