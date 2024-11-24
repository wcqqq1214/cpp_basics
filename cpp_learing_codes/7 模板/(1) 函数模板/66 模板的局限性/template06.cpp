#include <iostream>
using namespace std;

//模板-模板的局限性

//模板并不是万能的，有些特定的数据类型，需要用具体化方式做特殊实现

//总结:
//1. 利用具体化的模板，可以解决自定义数据类型的通用化
//2. 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板


class Person {

public:

    Person(string name, int age) {

        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;  //姓名
    int m_Age;      //年龄 
};

//对比两个数据是否相等的函数
template<typename T>
bool myCompare(T &a, T &b) {

    if (a == b) {
        return true;
    }
    else {
        return false;
    }
}

//利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person &p1, Person &p2) {

    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
        return true;
    }
    else {
        return false;
    }
}

void test01() {

    int a = 10;
    int b = 20;

    bool res = myCompare(a, b);

    if (res) {
        cout << "a == b" << '\n';
    }
    else {
        cout << "a != b" << '\n';
    }
}

void test02() {

    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool res = myCompare(p1, p2);

    if (res) {
        cout << "p1 == p2" << '\n';
    }
    else {
        cout << "p1 != p2" << '\n';
    }
}


int main() {

    // test01();

    test02();
    
    system("pause");

    return 0;
}