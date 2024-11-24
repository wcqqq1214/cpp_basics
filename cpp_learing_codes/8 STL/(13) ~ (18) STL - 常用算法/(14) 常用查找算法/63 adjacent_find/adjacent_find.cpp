#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法-adjacent_find


//功能:
//查找相邻重复元素


//函数原型:

//adjacent_find(iterator beg, iterator end);
//查找相邻重复元素, 返回相邻元素的第一个位置的迭代器
//beg   开始迭代器
//end   结束迭代器


void test01() {

    vector<int> v;
    v.push_back(0);    
    v.push_back(2);    
    v.push_back(0);    
    v.push_back(3);    
    v.push_back(1);    
    v.push_back(4);    
    v.push_back(3);    
    v.push_back(3);    

    auto pos = adjacent_find(v.begin(), v.end());

    if (pos == v.end()) {

        cout << "未找到相邻重复元素" << '\n';
    }
    else {

        cout << "找到相邻重复元素: " << *pos << '\n';
    }
}

int main() {

    test01();

    system("pause");

    return 0;
}