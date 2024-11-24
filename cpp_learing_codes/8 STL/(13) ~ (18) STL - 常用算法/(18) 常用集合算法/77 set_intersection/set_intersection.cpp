#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//算法简介:

//set_intersection      //求两个容器的交集
//set_union             //求两个容器的并集
//set_difference        //求两个容器的差集



//常用集合算法-set_intersection (intersection: 相交)

//功能:
//求两个容器的交集


//函数原型:
//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

//beg1  容器1开始迭代器
//end1  容器1结束迭代器
//beg2  容器2开始迭代器
//end2  容器2结束迭代器
//dest  目标容器开始迭代器

//ps: 两个集合必须是有序序列!!!


//总结:
//1. 求交集的两个集合必须是有序序列

//2. 目标容器开辟空间需要从两个容器中取最小值 

//3. set_intersection返回值 即是 交集最后一个元素的下一位 的迭代器


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
    //最特殊的情况: 大容器包含小容器    则开辟空间 取小容器的size即可
    vTarget.resize(min(v1.size(), v2.size()));

    //获取交集
    //返回 交集最后一个元素下一位 的迭代器
    auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}