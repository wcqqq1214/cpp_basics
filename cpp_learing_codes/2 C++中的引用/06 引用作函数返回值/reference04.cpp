#include <iostream>
using namespace std;

//引用作函数返回值

//1. 不要返回局部变量的引用 (错误例子)
/*
int& test01() {

    int a = 10; //局部变量存放在四区中的 栈区
    return a;
}
*/

//2. 函数的调用可以作为左值
int& test02() {

    static int a = 10;  //静态变量，存放在 全局区，全局区上的数据在程序结束后系统释放
    return a;
}

int main() {

    //int &res = test01();

    //cout << "res = " << res << '\n';  //第一次结果正确，是因为编译器做了保留
    //cout << "res = " << res << '\n';  //第二次结果错误，是因为a的内存已经释放

    int &res = test02();
    cout << "res = " << res << '\n';
    cout << "res = " << res << '\n';

    test02() = 1000;    //如果函数的返回值为引用，这个函数的调用可以作为左值

    cout << "res = " << res << '\n';
    cout << "res = " << res << '\n';

    system("pause");

    return 0;
}