#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法-binary_search


//功能:
//查找指定元素是否存在


//函数原型:
//bool binary_search(iterator beg, iterator end, value);

//查找指定元素, 查到返回true, 否则false
//beg   开始迭代器
//end   结束迭代器
//value 查找的元素

//ps: 在无序序列中不可用


void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    //查找容器中是否有9元素
    bool ret = binary_search(v.begin(), v.end(), 9);

    if (ret) {
        cout << "找到元素" << '\n';
    }
    else {
        cout << "没有找到元素" << '\n';
    }
}

int main() {

    test01();

    system("pause");

    return 0;
}