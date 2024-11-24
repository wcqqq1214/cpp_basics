#include <iostream>
using namespace std;

//多态-多态的基本语法


//多态分为两类

//1. 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
//2. 动态多态：派生类 和 虚函数 实现运行时多态


//静态多态和动态多态区别：

//1. 静态多态的函数地址早绑定 - 编译阶段确定函数地址
//2. 动态多态的函数地址晚绑定 - 运行阶段确定函数地址


//动物类
class Animal {

public:
    //虚函数
    virtual void speak() {
        cout << "动物在说话" << '\n';
    }
};

//猫类
class Cat: public Animal {

public:

    void speak() {
        cout << "小猫在说话" << '\n';
    }
};

//动态多态满足条件：
//1. 有继承关系
//2. 子类重写父类的虚函数   (重写：函数返回值  函数名  参数列表  完全相同)

//动态多态使用：
//父类的指针或者引用  指向子类的对象

//执行说话的函数
//如果想执行让猫说话  那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，即晚绑定
void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;
    doSpeak(cat);
}

int main() {

    test01();

    system("pause");

    return 0;
}