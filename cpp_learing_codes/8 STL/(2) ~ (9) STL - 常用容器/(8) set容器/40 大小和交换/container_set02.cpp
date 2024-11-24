#include <iostream>
using namespace std;
#include <set>

//set容器-大小和交换


//函数原型:

//size();           //返回容器中元素的数目

//empty();          //判断容器是否为空

//swap(st);         //交换两个集合容器

//ps: 没有提供 resize() 方法


void printSet(const set<int> &s) {

    for (auto it = s.begin(); it != s.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

//大小
void test01() {

    set<int> s1;

    //插入数据
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    //打印容器
    printSet(s1);

    //判断是否为空
    if (s1.empty()) {

        cout << "s1为空" << '\n';
    }
    else {

        cout << "s1不为空" << '\n';
        cout << "s1的大小为: " << s1.size() << '\n';
    }
}

//交换
void test02() {

    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int> s2;

    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);

    cout << "交换前: " << '\n';
    printSet(s1);
    printSet(s2);

    //交换
    s1.swap(s2);

    cout << "交换后: " << '\n';
    printSet(s1); 
    printSet(s2); 
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}