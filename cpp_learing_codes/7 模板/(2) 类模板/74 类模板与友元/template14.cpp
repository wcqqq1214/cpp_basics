#include <iostream>
using namespace std;

//模板-类模板与友元


//类模板配合友元函数的类内和类外实现

//1. 全局函数类内实现:  直接在类内声明友元

//2. 全局函数类外实现:  需要提前让编译器知道全局函数的存在  (建议使用！！！用法简单，而且编译器可以直接识别)


//通过全局函数 打印Person信息


//2. 全局函数配合友元 类外实现  - 先做函数模板声明，下方再做函数模板定义，再做友元
template<class T1, class T2>
class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现写到类的前面让编译器提前看到
// template<class T1, class T2>
// void printPerson2(Person<T1, T2> &p);

template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {   //实现中用到了Person类，所以要在前面声明Person类

    cout << "name = " << p.m_Name << '\n';
    cout << "age = " << p.m_Age << '\n';
}


template<class T1, class T2>
class Person {

    //1. 全局函数 类内实现 (全局函数做友元)
    friend void printPerson1(Person<T1, T2> p) { //参数模板化 传参

        cout << "name = " << p.m_Name << '\n';
        cout << "age = " << p.m_Age << '\n';
    }

    //2. 全局函数 类外实现
    //加空模板参数列表
    //如果全局函数 是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);   //加上 <> 来表明这是一个函数模板

public:

    Person(T1 name, T2 age) {

        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};


//1. 全局函数类内实现 test01()
void test01() {

    Person<string, int> p("Tom", 21);
    printPerson1(p);
}

//2. 全局函数类外实现 test02()
void test02() {

    Person<string, int> p("Jerry", 19);
    printPerson2(p);
}


int main() {

    // test01();

    test02();
    
    system("pause");

    return 0;
}