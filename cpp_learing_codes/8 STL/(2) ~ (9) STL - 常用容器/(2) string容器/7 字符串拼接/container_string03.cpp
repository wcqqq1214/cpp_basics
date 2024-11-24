#include <iostream>
using namespace std;

//string容器-字符串拼接


//函数原型:

//string& operator+=(const char* str);      //重载+=操作符

//string& operator+=(const char c);         //重载+=操作符

//string& operator+=(const string &str);    //重载+=操作符


//string& append(const char* s);                    //把字符串s连接到当前字符串结尾

//string& append(const char* s, int n);             //把字符串s的前n个字符连接到当前字符串结尾

//string& append(const string &s);                  //同operator+=(const string &str)

//string& append(const string &s, int pos, int n);  //字符串s从pos开始的n个字符连接到字符串的结尾


#include <string>

void test01() {

    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1 = " << str1 << '\n';

    str1 += ':';
    cout << "str1 = " << str1 << '\n';

    string str2 = "LOL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << '\n';


    string str3 = "I";
    str3.append(" love ");
    cout << "str3 = " << str3 << '\n';

    str3.append("game abcde", 4);
    cout << "str3 = " << str3 << '\n';
    
    // str3.append(str2);
    // cout << "str3 = " << str3 << '\n';

    // str3.append(str2, 0, 3);    //只截取LOL

    str3.append(str2, 4, 3);    //只截取DNF
    //ps: 截取的字符不包括pos位置, 应为pos往后推n个    
    cout << "str3 = " << str3 << '\n';
}


int main() {

    test01();    

    system("pause");

    return 0;
}
