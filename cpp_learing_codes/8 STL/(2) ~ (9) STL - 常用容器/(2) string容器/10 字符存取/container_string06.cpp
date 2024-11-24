#include <iostream>
using namespace std;

//string容器-字符存取


//函数原型:

//char& operator[](int n);  //通过 [] 方式存取字符

//char& at(int n);          //通过 at 方法存取字符


void test01() {

    string str = "Hello world";

    //1. 通过 [] 访问单个字符
    for (int i = 0; i < str.size(); i++) {

        cout << str[i] << " ";
    }
    cout << '\n';

    //2. 通过 at 方法访问单个字符
    for (int i = 0; i < str.size(); i++) {

        cout << str.at(i) << " ";
    }
    cout << '\n';

    //修改的单个字符
    str[0] = 'x';
    str.at(1) = 'x';
    cout << "str = " << str << '\n';    //xxllo world
}


int main() {

    test01();

    system("pause");

    return 0;
}