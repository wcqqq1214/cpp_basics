#include <iostream>
using namespace std;

//string容器-字符串查找和替换


//查找: 查找指定字符串是否存在
//替换: 在指定的位置替换字符串

//find 是 从左向右 查找 第一次出现的位置，rfind 是 从右向左 查找 最后一次出现的位置
//找到字符串后返回查找的第一个字符位置, 找不到返回-1


//函数原型:

//int find(const string &str, int pos = 0) const;       //查找str第一次出现的位置, 从pos开始查找

//int find(const char* s, int pos = 0) const;           //查找s第一次出现的位置, 从pos开始查找

//int find(const char* s, int pos, int n) const;        //从pos位置查找s的前n个字符第一次出现的位置

//int find(const char c, int pos = 0) const;            //查找字符c第一次出现的位置


// (r 表示 reverse 反向)
// (rfind 默认从右向左查找)
//int rfind(const string &str, int pos = npos) const;   //查找str最后一次出现的位置, 从pos开始查找

//int rfind(const char* s, int pos = npos) const;       //查找s最后一次出现的位置, 从pos开始查找

//int rfind(const char* s, int pos, int n) const;       //从pos开始查找s的前n个字符最后一次出现的位置

//int rfind(const char c, int pos = 0) const;           //查找字符c最后一次出现的位置


//string& replace(int pos, int n, const string &str);   //替换从pos开始n个字符为字符串str

//string& replace(int pos, int n, const char* s);      //替换从pos开始n个字符为字符串s


#include <string>

//1. 查找
void test01() {

    string str1 = "abcdefgde";

    //find
    int pos = str1.find("de");  //pos = 3 (从0开始索引, d为3)

    if (pos == -1) {        //未找到, 返回-1

        cout << "未找到字符串" << '\n';
    }
    else {
        cout << "找到字符串, pos = " << pos << '\n';
    }

    //rfind
    pos = str1.rfind("de"); //pos = 7

    cout << "pos = " << pos << '\n';
}


//2. 替换
void test02() {

    string str1 = "abcdefg";

    //从 1号位置起 3个字符 替换为 "1111"
    str1.replace(1, 3, "1111"); // "bcd" => "1111"

    cout << "str1 = " << str1 << '\n';
}



int main() {

    test01();

    test02();

    system("pause");

    return 0;
}