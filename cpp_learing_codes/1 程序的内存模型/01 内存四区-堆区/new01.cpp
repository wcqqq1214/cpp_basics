#include <iostream>
using namespace std;

//内存四区——堆区

//堆区数据利用new关键字进行开辟内存
//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete

int* func() {

    //利用new关键字，可以将数据开辟到堆区 (语法：new 数据类型，利用new创建的数据，会返回该数据对应类型的指针)
    //指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    int *p = new int(10);   //括号内存放数据的初始值
    return p;
}

int main() {

    int *p = func();

    cout << *p << endl;

    system("pause");

    return 0;
}