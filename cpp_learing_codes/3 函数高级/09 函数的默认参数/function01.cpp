#include <iostream>
using namespace std;

//函数的默认参数

//如果我们自己传入了数据，就用自己的数据，如果没有则用默认值
int func(int a, int b = 20, int c = 10) {

    return a + b + c;
}

//注意事项
//1. 如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值

//2. 如果函数声明有默认参数，函数实现就不能有默认参数 (声明和实现只能有一个有默认参数)
int func1(int a = 10, int b = 10);    //函数声明

int func1(int a, int b) {   //函数实现

    return a + b;
}

int main() {

    cout << func(10) << '\n';


    system("pause");

    return 0;
}