#include <iostream>
using namespace std;

//运算符重载 —— 关系运算符重载 (>, <, >=, <=, ==, !=)

//作用：可以让两个自定义类型对象进行对比操作

class Person {

public:

    string m_Name;
    int m_Age;

    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
    }

    //重载 ==
    bool operator==(const Person& p) {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        }
        return false;
    }
};

void test01() {

    Person p1("Tom", 18);
    
    Person p2("Jerry", 18);

    if (p1 == p2) {
        cout << "p1 和 p2是相等的" << '\n';
    } else {
        cout << "p1 和 p2是不相等的" << '\n';
    }
}

int main() {

    test01();

    system("pause");

    return 0;
}