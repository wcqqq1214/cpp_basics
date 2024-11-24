#include <iostream>
using namespace std;

//引用的基本语法

int main() {

    //引用基本语法：
    //数据类型 &别名 = 原名
    
    int a = 10;
    //创建引用
    int &b = a;
    
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    b = 100;

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    system("pause");

    return 0;
}