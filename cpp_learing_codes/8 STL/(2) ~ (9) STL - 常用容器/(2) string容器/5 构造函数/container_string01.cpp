#include <iostream>
using namespace std;

//string容器-构造函数


//string基本概念

//本质: 
//string是C++风格的字符串, 而string本质上是一个类

//string和char*区别:
//char*是一个指针
//string是一个类, 类内部封装了char*, 管理这个字符串, 是一个char*型的容器


//string构造函数
//构造函数原型:

//string();                     //创建一个空的字符串, 例如: string str;
//string(const char* s);        //使用字符串s初始化

//string(const string &str);    //使用一个string对象初始化另一个string对象  (拷贝构造)

//string(int n, char c);        //使用n个字符c初始化


#include <string>

void test01() {

    string s1;      //默认构造

    const char* str = "Hello world!";
    string s2(str);     //使用字符串s初始化

    cout << "s2 = " << s2 << '\n';

    string s3(s2);      //使用一个string对象初始化另一个string对象  (拷贝构造)

    cout << "s3 = " << s3 << '\n';

    string s4(10, 'a');     //使用n个字符c初始化

    cout << "s4 = " << s4 << '\n';
}


int main() {

    test01();

    system("pause");

    return 0;
}