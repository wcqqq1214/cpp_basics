#include <iostream>
using namespace std;

//const修饰成员函数 (常函数和常对象)

//常函数：
//1. 成员函数后加const，我们称这个函数为常函数
//2. 常函数内不可以修改成员属性
//3. 成员属性声明时加关键字mutable后，在常函数中依然可以修改


//常对象：
//1. 声明对象前加const，称该对象为常对象
//2. 常对象只能调用常函数


class Person {

public:

    int m_A;
    mutable int m_B;    //特殊变量，即使在常函数下，也可以修改这个值

    Person() {
        
    }

    //this指针的本质  是指针常量  指针的指向是不可以修改的
    //Person* const this
    //在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以更改
    void showPerson() const {
        
        // this->m_A = 100;
        this->m_B = 100;
    }

    void func() {

    }

};

void test01() {

    Person p;
    p.showPerson();
}

void test02() {

    const Person p; //在对象前加const，变为常对象
    // p.m_A = 100;
    p.m_B = 100;

    //常对象只能调用常函数
    p.showPerson();
    // p.func();    //常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main() {

    test01();
    
    test02();

    system("pause");

    return 0;
}