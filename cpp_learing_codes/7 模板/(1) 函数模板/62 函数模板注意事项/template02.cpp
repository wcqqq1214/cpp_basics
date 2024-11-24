#include <iostream>
using namespace std;

//模板-函数模板注意事项


//利用模板提供通用的交换函数
template<typename T>
void mySwap(T &a, T &b) {

    T temp = a;
    a = b;
    b = temp;
}

//1. 自动类型推导，必须推导出一致的数据类型T，才可以使用
void test01() {

    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a, b);   //正确
    // mySwap(a, c);   //错误

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
}


//2. 模板必须要确定出T的数据类型，才可以使用
template<typename T>
void func() {

    cout << "func() 调用" << '\n';
}

void test02() {

    func<int>();
    // func();  //错误
}


int main() {

    test01();

    test02();

    system("pause");

    return 0;
}