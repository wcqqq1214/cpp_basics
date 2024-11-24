#include <iostream>
using namespace std;

//模板-普通函数与函数模板区别


//1. 普通函数调用时可以发生 自动类型转换 (隐式类型转换)

//2. 函数模板调用时，如果利用 自动类型推导，不会发生 隐式类型转换 

//3. 如果利用 显式指定类型 的方式，可以发生 隐式类型转换

//总结: 建议使用显式指定类型的方式，调用函数模板，因为可以自己确定通用类型T


//普通函数
int myAdd01(int a, int b) {
    
    return a + b;
}

//函数模板
template<typename T>
T myAdd02(T a, T b) {

    return a + b;
}

void test01() {

    int a = 10;
    int b = 20;
    char c = 'c';
    
    cout << myAdd01(a, c) << '\n';

    //自动类型推导  (不会发生 隐式类型转换)
    cout << myAdd02(a, b) << '\n';
    // cout << myAdd02(a, c) << '\n';   //错误

    //显式指定类型  (可以发生 隐式类型转换)
    cout << myAdd02<int>(a, c) << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}