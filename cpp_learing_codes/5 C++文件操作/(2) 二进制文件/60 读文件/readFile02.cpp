#include <iostream>
using namespace std;

//二进制文件-读文件


//二进制方式写文件主要利用流对象调用成员函数read
//函数原型: istream& read(char* buffer, int len);
//参数解释: 字符指针buffer指向内存中一段存储空间    len是读写的字节数


//1. 包含头文件
#include <fstream>

class Person {

public:
    char m_Name[64];    //姓名
    int m_Age;          //年龄
};

void test01() {

    //2. 创建流对象
    ifstream ifs;

    //3. 打开文件   判断文件是否打开成功
    ifs.open("D:/VS Code Project/cpp_learning/5 C++文件操作/(2) 二进制文件/59 写文件/person.txt", ios::in | ios::binary);

    if ( !ifs.is_open() ) {
        cout << "文件打开失败" << '\n';
        return;
    }

    //4. 读文件
    Person p;
    ifs.read( (char*)&p, sizeof(p) );

    cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << '\n';

    //5. 关闭文件
    ifs.close();

}

int main() {

    test01();

    system("pause");

    return 0;
}