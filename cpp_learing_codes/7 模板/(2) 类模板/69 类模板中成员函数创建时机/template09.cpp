#include <iostream>
using namespace std;

//模板-类模板中成员函数创建时机


//类模板中成员函数 和 普通类中成员函数 创建时机的区别: 

//1. 普通类中的成员函数 一开始就可以创建

//2. 类模板中的成员函数 在调用时才创建


class Person1 {

public:

    void showPerson1() {

        cout << "Person1 show" << '\n';
    }
};

class Person2 {

public:

    void showPerson2() {

        cout << "Person2 show" << '\n';
    }
};

template<class T>
class MyClass {

public:

    T obj;  //无法确定obj的数据类型，直到调用的时候才知道是什么数据类型

    //类模板中的成员函数
    void func1() {

        obj.showPerson1();
    }

    void func2() {

        obj.showPerson2();
    }
};

void test01() {

    MyClass<Person1> m1;
    m1.func1();

    MyClass<Person2> m2;
    m2.func2();
}



int main() {

    test01();
    
    system("pause");

    return 0;
}