#include <iostream>
using namespace std;
#include <map>

//map容器-大小和交换


//函数原型:

//size();           //返回容器中元素的数目

//empty();          //判断容器是否为空

//swap(mp);         //交换两个map容器


void printMap(const map<int, int> &m) {

    for (auto it = m.begin(); it != m.end(); it++) {

        cout << "key = " << it->first << " value = " << it->second << '\n';
    }
    cout << '\n';
}

//大小
void test01() {

    map<int, int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if (m.empty()) {

        cout << "m为空" << '\n';
    }
    else {

        cout << "m不为空" << '\n';
        cout << "m的大小为: " << m.size() << '\n';
    }
}

//交换
void test02() {

    map<int, int> m1;

    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));

    map<int, int> m2;

    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前: " << '\n';
    printMap(m1);
    printMap(m2);

    //交换
    m1.swap(m2);

    cout << "交换后: " << '\n';
    printMap(m1); 
    printMap(m2); 
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}