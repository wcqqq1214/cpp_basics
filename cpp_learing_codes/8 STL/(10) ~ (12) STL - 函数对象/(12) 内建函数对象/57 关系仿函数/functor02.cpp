#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>

//内建函数对象-关系仿函数


//功能:
//实现关系对比


//仿函数原型:

//template<class T> bool equal_to<T>        //等于

//template<class T> bool not_equal_to<T>    //不等于

//template<class T> bool greater<T>         //大于 (最常用!!!)

//template<class T> bool greater_equal<T>   //大于等于

//template<class T> bool less<T>            //小于

//template<class T> bool less_equal<T>      //小于等于


class MyCompare {

public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

//大于  greater
void test01() {

    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';

    //降序
    // sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());   //greater<int>()    内建函数对象

    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}