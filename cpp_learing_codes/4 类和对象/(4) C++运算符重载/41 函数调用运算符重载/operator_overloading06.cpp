#include <iostream>
using namespace std;

//运算符重载 —— 函数调用运算符重载 ()   (STL中有用到！！)


class MyPrint {

public:

    //重载函数调用运算符
    void operator()(string text) {
        
        cout << text << '\n';
    }

};

void test01() {

    MyPrint myprint;

    myprint("Hello world!");    //由于重载后使用的方式非常像函数的调用，因此称为仿函数
}

//仿函数没有固定写法，非常灵活
//加法类
class MyAdd {

public:
    
    int operator()(int n1, int n2) {
        return n1 + n2;
    }

};

void test02() {

    MyAdd myAdd;
    
    int res = myAdd(10, 20);

    cout << "res = "<< res << '\n';

    //匿名函数对象  =>  类型()  当前行执行完之后，立即被释放
    cout << "MyAdd()(100, 200) = "<< MyAdd()(100, 200) << '\n';
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}