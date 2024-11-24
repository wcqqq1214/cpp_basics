#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

//常用算术生成算法-fill


//功能:
//将容器区间内的元素填充为 指定的值


//函数原型:
//fill(iterator beg, iterator end, value);

//beg   开始迭代器
//end   结束迭代器 
//value 填充的值


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v;
    v.resize(10);   //填充默认值0

    //后期重新填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}