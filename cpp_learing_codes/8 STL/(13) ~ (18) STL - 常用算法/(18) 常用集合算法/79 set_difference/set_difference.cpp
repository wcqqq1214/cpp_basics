#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用集合算法-set_difference


//功能:
//求两个容器的差集


//V1容器: 0 1 2 3 4     5  6  7  8  9
//V2容器: 5 6 7 8 9     10 11 12 13 14
//V1和V2容器    差集: 0  1  2  3  4
//V2和V1容器    差集: 10 11 12 13 14


//函数原型:
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

//beg1  容器1开始迭代器
//end1  容器1结束迭代器
//beg2  容器2开始迭代器
//end2  容器2结束s迭代器
//dest  目标容器开始迭代器

//ps: 两个集合必须是有序序列!!!


//总结:
//1. 求差集的两个集合必须是有序序列

//2. 目标容器开辟空间需要从 两个容器取最大值

//3. set_difference返回值 即是 交集最后一个元素的下一位 的迭代器


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v1;
    vector<int> v2;    
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);        //0 ~ 9
        v2.push_back(i + 5);    //5 ~ 14
    }

    vector<int> vTarget;
    //目标容器需要提前开辟空间
    //最特殊的情况: 两个集合没有交集    则开辟空间 取大容器的size
    vTarget.resize(max(v1.size(), v2.size()));

    //获取差集
    //返回 差集最后一个元素下一位 的迭代器
    
    cout << "v1和v2的差集为: " << '\n';
    auto itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << '\n';

    cout << "v2和v1的差集为: " << '\n';
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}