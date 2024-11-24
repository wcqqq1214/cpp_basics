#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

//ps: 算术生成算法属于小型算法, 使用时包含的头文件为 #include <numeric>

//算法简介:
//accumulate        //计算容器元素累计总和

//fill              //向容器内添加元素



//常用算术生成算法-accumulate

//功能:
//计算区间内 容器元素累计总和


//函数原型:
//accumulate(iterator beg, iterator end, value);

//beg   开始迭代器
//end   结束迭代器
//value 起始值


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v;

    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }

    //参数3 起始累加值
    int sum = accumulate(v.begin(), v.end(), 0);

    cout << "sum = " << sum << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}