#include <iostream>
using namespace std;
#include <set>

//pair使用-pair对组的创建


//功能描述:
//成对出现的数据, 利用对组可以返回两个数据


//两种创建方式:

//pair<type, type> p ( value1, value2 );

//pair<type, type> p = make_pair( value1, value2 );


//pair对组创建
void test01() {

    //第一种方式
    pair<string, int> p1(string("Tom"), 20);
    
    cout << "name = " << p1.first << "\tage = " << p1.second << '\n';

    //第二种方式
    pair<string, int> p2 = make_pair(string("Jerry"), 10);
    
    cout << "name = " << p2.first << "\tage = " << p2.second << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}