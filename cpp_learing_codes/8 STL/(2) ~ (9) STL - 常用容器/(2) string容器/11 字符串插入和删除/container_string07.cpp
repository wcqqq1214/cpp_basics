#include <iostream>
using namespace std;

//string容器-字符串插入和删除


//函数原型:

//string& insert(int pos, const char* s);           //插入字符串

//string& insert(int pos, const string &str);       //插入字符串

//string& insert(int pos, int n, char c);           //在指定位置插入n个字符c

//string& erase(int pos, int n = npos);             //删除从pos开始的n个字符
// (当 n = npos 时，表示删除从 pos 开始直到字符串结尾的所有字符)

//插入和删除的起始下标都是从0开始


#include <string>

void test01() {

    string str = "Hello";

    //插入
    str.insert(1, "111");   //在第1位元素 'e' 的 前面插入 "111"
    cout << "str = " << str << '\n';    //str = H111ello

    //删除
    str.erase(1, 3);
    cout << "str = " << str << '\n';
}


int main() {

    test01();

    system("pause");

    return 0;
}