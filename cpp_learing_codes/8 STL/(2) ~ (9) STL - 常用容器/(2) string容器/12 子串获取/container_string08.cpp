#include <iostream>
using namespace std;

//string容器-子串获取


//函数原型:

//string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串


#include <string>

void test01() {

    string str = "abcdef";

    string subStr = str.substr(1, 3);   //subStr = bcd

    cout << "subStr = " << subStr << '\n';
}

//实用操作
void test02() {

    string email = "weichengqian@gmail.com";

    //从邮件地址中 获取 用户名信息
    int pos = email.find('@');  //pos = 12

    string userName = email.substr(0, pos);

    cout << "userName = " << userName << '\n';
}


int main() {

    test01();

    test02();

    system("pause");

    return 0;
}
