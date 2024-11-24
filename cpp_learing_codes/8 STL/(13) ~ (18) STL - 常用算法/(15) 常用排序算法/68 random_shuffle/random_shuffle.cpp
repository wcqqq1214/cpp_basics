#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

//常用排序算法-random_shuffle


//功能:
//洗牌, 指定范围内的元素随机调整次序

//函数原型:
//random_shuffle(iterator beg, iterator end);

//beg   开始迭代器
//end   结束s迭代器

//总结: 使用时记得添加随机数种子


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    //添加随机数种子
    srand((unsigned int)time(NULL));

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }    

    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';

    //利用洗牌算法打乱顺序
    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}