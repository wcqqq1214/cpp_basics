#include <iostream>
using namespace std;
#include <set>

//(有序集容器)
//set容器-构造和赋值


//简介:
//所有元素都会在插入时自动被排序

//本质:
//set/multiset属于关联式容器, 底层结构是用二叉树实现

//set和multiset区别:
//set不允许容器中有重复的元素
//multiset允许容器中有重复的元素


//函数原型:

//构造:
//set<T> &st;                   //默认构造函数
//set(const set &st);           //拷贝构造函数

//赋值:
//set& operator=(const set &st);    //重载 = 操作符


void printSet(const set<int> &s) {

    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    set<int> s1;

    //插入数据  只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

    //遍历容器
    //1. 所有元素插入时候自动被排序
    //2. 不允许插入重复值
    printSet(s1);   //10 20 30 40

    //拷贝构造
    set<int> s2(s1);

    printSet(s2);

    //赋值
    set<int> s3;
    s3 = s2;

    printSet(s3);
}

int main() {

    test01();

    system("pause");

    return 0;
}