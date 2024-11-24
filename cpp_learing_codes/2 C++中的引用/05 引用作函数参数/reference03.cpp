#include <iostream>
using namespace std;

//引用作函数参数

//地址传递
/*
void mySwap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}
*/

//引用传递
void mySwap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 10;
    int b = 20;
    mySwap(a, b);   //引用传递，形参也会修饰实参

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    system("pause");

    return 0;
}