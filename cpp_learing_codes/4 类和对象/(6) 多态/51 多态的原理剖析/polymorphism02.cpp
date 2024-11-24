#include <iostream>
using namespace std;

//多态-多态的原理剖析
//黑马 P136 54 类和对象-多态-多态的原理剖析
//https://www.bilibili.com/video/BV1et411b73Z/?p=136&vd_source=a622847f114b1b2a92fb125fffb02cf3

//动物类
class Animal {

public:

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

void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;
    doSpeak(cat);
}

void test02() {
    cout << "sizeof Animal = " << sizeof(Animal) << '\n';
}

int main() {

    // test01();

    test02();

    system("pause");

    return 0;
}