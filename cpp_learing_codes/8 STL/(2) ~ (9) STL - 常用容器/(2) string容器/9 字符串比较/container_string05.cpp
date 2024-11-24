#include <iostream>
using namespace std;

//string容器-字符串比较


//比较方式:
//字符串比较是按字符的ASCII码进行对比

// =  返回 0
// >  返回 1
// <  返回 -1


//函数原型:

//int compare(const string &s) const;  //与字符串s比较

//int compare(const char* s) const;  //与字符串s比较

//逐个字符比较 ASCII 码值，直到遇到不同字符或比较完成


#include <string>

void test01() {

    string str1 = "xello";
    string str2 = "hello";

    if (str1.compare(str2) == 0) {

        cout << "str1 等于 str2" << '\n';
    }
    else if (str1.compare(str2) > 0) {

        cout << "str1 大于 str2" << '\n';
    }
    else {

        cout << "str1 小于 str2" << '\n';
    }
}


int main() {

    test01();

    system("pause");

    return 0;
}