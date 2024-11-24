#include <iostream>
using namespace std;

//函数重载-注意事项 
//1. 引用作为重载的条件    
void func(int &a) { //若传入10，int &a = 10;  不合法

    cout << "func(int &a)的调用" << '\n';
}

void func(const int &a) {   //若传入10，const int &a = 10;  合法

    cout << "func(const int &a)的调用" << '\n';
}

//2. 函数重载碰到默认参数
void func2(int a, int b = 10) {

    cout << "func2(int a, int b)的调用" << '\n';
}

void func2(int a) {

    cout << "func2(int a)的调用" << '\n';
}

int main() {

    int a = 10;
    func(a);  //调用func(int &a)

    func(10);   //调用func(const int &a)

    //func2(10);    //当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况

    system("pause");

    return 0;
}