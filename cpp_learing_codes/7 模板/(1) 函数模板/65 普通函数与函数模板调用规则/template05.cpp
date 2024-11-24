#include <iostream>
using namespace std;

//模板-普通函数与函数模板调用规则


//调用规则如下:

//1. 如果函数模板和普通函数都可以实现，优先调用普通函数

//2. 可以通过空模板参数列表来强制调用函数模板

//3. 函数模板也可以发生重载

//4. 如果函数模板可以产生更好的匹配，优先调用函数模板

//总结: 既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性


void myPrint(int a, int b) {

    cout << "调用普通函数" << '\n';
}

template<typename T>
void myPrint(T a, T b) {

    cout << "调用函数模板" << '\n';
}

//函数模板发生重载
template<typename T>
void myPrint(T a, T b, T c) {

    cout << "调用重载的函数模板" << '\n';
}

void test01() {

    int a = 10;
    int b = 20;

    //调用普通函数
    myPrint(a, b);  

    //通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);
    
    //调用重载的函数模板
    myPrint(a, b, 100);

    //如果函数模板可以产生更好的匹配，优先调用函数模板 (理论上两个都能调用，但调用函数模板更好匹配)
    char c1 = 'a';
    char c2 = 'b';

    myPrint(c1, c2);
}


int main() {

    test01();

    system("pause");

    return 0;
}