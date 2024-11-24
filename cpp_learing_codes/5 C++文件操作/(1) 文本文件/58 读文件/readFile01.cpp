#include <iostream>
using namespace std;

//文本文件-读文件


//读文件步骤：
//1. 包含头文件
#include <fstream>

void test01() {

    //2. 创建流对象 (文件输入流)
    ifstream ifs;

    //3. 打开文件并判断文件是否打开成功
    //ifs.open("文件路径", 打开方式);     
    ifs.open("test2.txt", ios::in);

    if ( !ifs.is_open() ) {
        cout << "文件打开失败" << '\n';
        return;
    }

    //4. 读数据 (4种方式)
    
    //(1)
    // char buf[1024] = { 0 };
    // while ( ifs >> buf ) {
    //     cout << buf << '\n';
    // }

    //(2)
    // char buf[1024] = { 0 };
    // while ( ifs.getline(buf, sizeof(buf) ) ) {
    //     cout << buf << '\n';
    // }

    //(3)
    string buf;
    while ( getline(ifs, buf) ) {
        cout << buf << '\n';
    }

    //(4)   (不推荐用)  ps: get()为逐字符读取
    // char c;
    // while ( (c = ifs.get()) != EOF ) {  //EOF: end of file
    //     cout << c;
    // }

    //5. 关闭文件
    ifs.close();

}

int main() {

    test01();   

    system("pause");

    return 0;
}