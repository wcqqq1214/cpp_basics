#include <iostream>
using namespace std;

//this指针的用途

//每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

class Person {

public:

    int age;

    Person(int age) {
        //this指针指向被调用的成员函数所属的对象

        //1. 当形参和成员变量同名时，可用this指针来区分 (解决名称冲突)
        this->age = age;
    }

    //如果要返回对象本体，要使用 引用& 进行返回
    Person& PersonAddAge(Person &p) {

        this->age += p.age;
        //this指向p2的指针，而*this指向的就是p2这个对象本体

        //2. 返回对象本身用 *this
        return *this;
    }
};

void test01() {

    Person p1(18);
    cout << "p1的年龄为: " << p1.age << '\n';
}

void test02() {

    Person p1(10);

    Person p2(10);

    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

    cout << "p2的年龄为: " << p2.age << '\n';
}


int main() {

    // test01();
    test02();

    system("pause");

    return 0;
}