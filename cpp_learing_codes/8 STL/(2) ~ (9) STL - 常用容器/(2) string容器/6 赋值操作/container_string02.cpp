#include <iostream>
using namespace std;

//string容器-赋值操作


//赋值的函数原型:

//string& operator=(const char* s);     //char*类型字符串 赋值给当前的字符串

//string& operator=(const string &s);   //把字符串s赋给当前的字符串

//string& operator=(char c);            //字符赋值给当前的字符串


//string& assign(const char* s);        //把字符串s赋给当前字符串

//string& assign(const char* s, int n); //把字符串s的前n个字符赋给当前字符串

//string& assign(const string &s);      //把字符串s赋给当前字符串

//string& assign(int n, char c);        //把n个字符c赋给当前字符串


#include <string>

void test01() {

    string str1;
    str1 = "Hello world";
    cout << "str1 = " << str1 << '\n';

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << '\n';

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << '\n';


    string str4;
    str4.assign("Hello cpp");
    cout << "str4 = " << str4 << '\n'; 

    string str5;
    str5.assign("Hello cpp", 5);
    cout << "str5 = " << str5 << '\n';

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << '\n'; 

    string str7;
    str7.assign(10, 'w');
    cout << "str7 = " << str7 << '\n';
}


int main() {

    test01();

    system("pause");

    return 0;
}