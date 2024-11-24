#include <iostream>
using namespace std;

//模板-函数模板基本语法

//C++另一种编程思想称为 泛型编程，主要利用的技术就是模板
//C++提供两种模板机制: 函数模板 和 类模板


//函数模板作用:     (提高复用性)
//建立一个通用函数，其函数 返回值类型 和 形参类型 可以不具体指定，用一个 虚拟的类型 代表

//函数模板语法:
// template<typename T>
// (这里写函数声明或定义)

//解释:
//template      ——————声明创建模板
//typename      ——————表明其后面的符号是一种数据类型，可以用class代替
//T     ——————通用的数据类型，名称可以任意，通常为大写字母 (虚拟类型)


//交换两个整型的函数
void swapInt(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

//交换两个浮点型的函数
void swapDouble(double &a, double &b) {

    double temp = a;
    a = b;
    b = temp;
}


//利用模板提供的通用交换函数
template<typename T>    //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b) {

    T temp = a;
    a = b;
    b = temp;
}

void test01() {

    int a = 20;
    int b = 10;

    //利用函数模板交换
    //两种方式使用函数模板

    //1. 自动类型推导    
    mySwap(a, b);
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    double c = 1.1;
    double d = 2.2;

    //2. 显示指定数据类型
    mySwap<double>(c, d);
    cout << "c = " << c << '\n';
    cout << "d = " << d << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}