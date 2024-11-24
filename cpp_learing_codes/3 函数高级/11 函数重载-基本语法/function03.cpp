#include <iostream>
using namespace std;

//函数重载-基本语法 (函数名可以相同，提高复用性)

//满足条件：
//1. 同一个作用域下
//2. 函数名称相同
//3. 函数参数 类型不同 或者 个数不同 或者 顺序不同

//注意：函数的返回值不可以作为函数重载的条件

void func() {

    cout << "func()的调用" << '\n';
}

void func(int a) {

    cout << "func(int a)的调用" << '\n';
}

int main() {

    func();
    func(10);

    system("pause");

    return 0;
}