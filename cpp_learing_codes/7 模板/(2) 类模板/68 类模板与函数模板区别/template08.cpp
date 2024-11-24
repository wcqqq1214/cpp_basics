#include <iostream>
using namespace std;

//模板-类模板和函数模板区别

//1. 类模板 没有自动类型推导 的使用方式 (只有显式指定类型!!!)
//2. 类模板在模板参数列表中 可以有默认参数

template<class NameType, class AgeType = int>   //类模板在模板参数列表中 可以有默认参数
class Person {

public:

    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name = " << this->m_Name << '\n';
        cout << "age = " << this->m_Age << '\n';
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01() {

    //1. 类模板 没有自动类型推导 的使用方式
    // Person p1("Jerry", 20);      //错误
    Person<string, int> p("Jerry", 20);    //正确
    
    p.showPerson();
}

void test02() {

    Person<string> p("Tom", 19);

    p.showPerson();
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}