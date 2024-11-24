#include <iostream>
using namespace std;

//二进制文件-写文件


//打开方式要指定为ios::binary

//二进制方式写文件主要利用流对象调用成员函数write
//函数原型: ostream& write(const char* buffer, int len);
//参数解释: 字符指针buffer指向内存中一段存储空间    len是读写的字节数


//1. 包含头文件
#include <fstream>

class Person {

public:

    char m_Name[64];    //姓名
    int m_Age;          //年龄
};

void test01() {

    //2. 创建流对象 并 打开文件
    ofstream ofs("person.txt", ios::out | ios::binary);

    //3. 写文件
    Person p = {"wcqqq", 21};
    ofs.write( (const char*)&p, sizeof(Person) );

    //4. 关闭文件
    ofs.close();

}

int main() {

    test01();

    system("pause");

    return 0;
}