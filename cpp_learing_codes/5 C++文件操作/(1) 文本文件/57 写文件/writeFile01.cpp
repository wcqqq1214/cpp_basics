#include <iostream>
using namespace std;

//文本文件-写文件


//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
//通过文件将数据持久化

//C++中对文件操作需要包含头文件 <fstream>

//文件类型分为两种：
//1. 文本文件   - 文件以文本的ASCII码形式存储在计算机中
//2. 二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

//操作文件的三大类
//1. ofstream:  写操作
//2. ifstream:  读操作
//3. fstream:   读写操作


//写文件步骤：
//1. 包含头文件
#include <fstream>

void test01() {

    //2. 创建流对象 (文件输出流对象)
    ofstream ofs;

    //3. 打开文件
    //ofs.open("文件路径", 打开方式);
    ofs.open("test1.txt", ios::out);    //如果没有指定路径，创建文件的路径默认和当前cpp文件一致

    //文件打开方式
    //(1) ios::in        为读文件而打开文件
    //(2) ios::out       为写文件而打开文件
    //(3) ios::ate       初始位置: 文件尾
    //(4) ios::app       追加方式写文件
    //(5) ios::trunc     如果文件存在先删除，再创建
    //(6) ios::binary    二进制方式

    //ps: 文件打开方式可以配合使用，利用 | 操作符

    //4. 写数据
    ofs << "你好!" << '\n';
    ofs << "Java is the best language.cpp" << '\n';
    ofs << "fuck Guangxi University" << '\n';

    //5. 关闭文件
    ofs.close();

}

int main() {

    test01();

    system("pause");

    return 0;
}