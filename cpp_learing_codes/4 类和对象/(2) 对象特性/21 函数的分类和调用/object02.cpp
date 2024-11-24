#include <iostream>
using namespace std;

//构造函数的分类和调用

//1. 构造函数分类
//按照参数分类分为  有参和无参构造  无参又称为默认构造函数
//按照类型分类分为  普通构造和拷贝构造

class Person {

public:

    int age;

    //无参构造函数(默认构造函数)
    Person() {
        cout << "Person 的无参构造函数调用" << '\n';
    }
    
    //有参构造函数
    Person(int a) {
        age = a;
        cout << "Person 的有参构造函数调用" << '\n';
    }

    //拷贝构造函数 (注意格式!!!)
    Person(const Person &p) {
        //将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person 的拷贝构造函数调用" << '\n';
    }

    //析构函数
    ~Person() {
        cout << "Person 的析构函数调用" << '\n';
    }
};

//2. 构造函数的调用
void test01() {

    //(1) 括号法 (常用)
    // Person p1;   //默认构造函数调用
    // Person p2(10);  //有参构造函数调用
    // Person p3(p2);  //拷贝构造函数调用

    //注意事项
    //调用默认构造函数时候，不要加()
    //因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
    // Person p1();

    //(2) 显示法
    Person p1;  //无参构造
    Person p2 = Person(10); //有参构造
    Person p3 = Person(p2); //拷贝构造

    // Person(10); //匿名对象  特点：当前行执行结束后，系统会立即回收掉匿名对象

    //注意事项
    //不要利用拷贝构造函数 初始化匿名对象，编译器会认为 Person(p3); 等价于 Person p3;

    //(3) 隐式转换法
    Person p4 = 10; //相当于 Person p4 = Person(10);
    Person p5 = p4; //拷贝构造
}



int main() {

    test01();

    system("pause");

    return 0;
}