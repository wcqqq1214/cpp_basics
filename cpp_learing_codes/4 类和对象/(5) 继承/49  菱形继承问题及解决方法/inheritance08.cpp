#include <iostream>
using namespace std;

//继承-菱形继承问题及解决方法

//菱形继承概念：    (又称为钻石继承)
//两个派生类继承同一个基类，又有某个类同时继承这两个派生类

//菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费


//动物类
class Animal {

public:
    int m_Age;
};

//利用虚继承  解决菱形继承的问题
//继承之前  加上关键字 virtual 变为虚继承
//Animal类称为 虚基类

//羊类
class Sheep: virtual public Animal {};

//驼类
class Camel: virtual public Animal {};

//羊驼类
class Alpaca: public Sheep, public Camel {};

void test01() {

    Alpaca a;

    a.Sheep::m_Age = 18;
    a.Camel::m_Age = 28;

    //当出现菱形继承时，两个父类拥有相同数据，需要加以作用域区分
    cout << "a.Sheep::m_Age = " << a.Sheep::m_Age << '\n';
    cout << "a.Camel::m_Age = " << a.Camel::m_Age << '\n';
    cout << "a.m_Age = " << a.m_Age << '\n';

}

int main() {

    test01();

    system("pause");

    return 0;
}