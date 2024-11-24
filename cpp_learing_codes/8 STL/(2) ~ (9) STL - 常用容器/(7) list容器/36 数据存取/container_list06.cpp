#include <iostream>
using namespace std;
#include <list>

//list容器-数据存取


//函数原型:

//front();      //返回第一个元素

//back();       //返回最后一个元素


void test01() {

    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // L1[0];      //错误, 不可以用[]访问list容器中的元素

    // L1.at(0);   //错误, 不可以用at方式访问list容器中的元素

    //原因: list本质是链表, 不是用连续线性空间存储数据, 迭代器也不支持随机访问

    cout << "第一个元素为: " << L1.front() << '\n';
    cout << "最后一个元素为: " << L1.back() << '\n';

    //验证迭代器是不支持随机访问的
    list<int>::iterator it = L1.begin();
    //支持自增和自减运算符 (即支持双向迭代器)
    it++;
    it--;
    // it = it + 1;    //错误, 不支持随机访问
}

int main() {

    test01();

    system("pause");

    return 0;
}