#include <iostream>
using namespace std;
#include <vector>

//vector容器-数据存取


//函数原型:

//at(int idx);      //返回索引idx所指的数据

//operator[];       //返回索引idx所指的数据 (重载 [] 运算符)

//front();          //返回容器中第一个数据元素

//back();           //返回容器中最后一个数据元素


void test01() {

    vector<int> v1;

    for (int i = 0; i < 10; i++) {

        v1.push_back(i);
    }


    //利用 [] 访问数组中元素
    for (int i = 0; i < 10; i++) {

        cout << v1[i] << " ";
    } 
    cout << '\n';


    //利用 at 方式访问元素
    for (int i = 0; i < 10; i++) {

        cout << v1.at(i) << " ";
    } 
    cout << '\n';


    //获取第一个元素
    cout << "第一个元素为: " << v1.front() << '\n';

    //获取最后一个元素
    cout << "最后一个元素为: " << v1.back() << '\n';
}


int main() {

    test01();

    system("pause");

    return 0;
}
