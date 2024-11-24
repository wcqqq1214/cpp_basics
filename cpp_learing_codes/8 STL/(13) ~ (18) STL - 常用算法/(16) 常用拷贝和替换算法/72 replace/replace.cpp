#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法-replace


//功能:
//将容器内指定范围的旧元素替换为新元素


//函数原型:
//replace(iterator beg, iterator end, oldvalue, newvalue);

//beg       开始迭代器
//end       结束迭代器
//oldvalue  旧元素
//newvalue  新元素


void myPrint(int val) {

    cout << val << " ";
}

void test01() {

    vector<int> v;

    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);

    cout << "替换前: " << '\n';
    for_each(v.begin(), v.end(), myPrint);
    cout << '\n';
    
    //把 20 替换为 2000
    replace(v.begin(), v.end(), 20, 2000);

    cout << "替换后: " << '\n';
    for_each(v.begin(), v.end(), myPrint);
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}