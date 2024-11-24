#include <iostream>
using namespace std;

//模板-类模板基本语法


//建立一个通用类，类中的成员 数据类型可以不具体指定，用一个 虚拟的类型 代表

//函数模板语法:
// template<typename T>
// (这里写函数声明或定义)

//解释:
//template      ——————声明创建模板
//typename      ——————表明其后面的符号是一种数据类型，可以用class代替
//T     ——————通用的数据类型，名称可以任意，通常为大写字母 (虚拟类型)


//类模板
template<class NameType, class AgeType>
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

    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}

int main() {

    test01();

    system("pause");

    return 0;
}