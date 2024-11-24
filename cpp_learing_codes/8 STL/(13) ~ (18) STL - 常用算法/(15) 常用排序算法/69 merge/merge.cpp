#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用排序算法-merge


//功能:
//两个容器元素合并, 并存储到另一容器中


//函数原型:
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

//beg1  容器1开始迭代器
//end1  容器1结束迭代器
//beg2  容器2开始迭代器
//end2  容器2结束迭代器
//dest  目标容器开始迭代器

//ps: 两个容器必须是有序的!!


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v1; //1 3 5 7 9
    vector<int> v2; //2 4 6 8 10

    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            v1.push_back(i);
        }
        else {    
            v2.push_back(i);
        }
    }

    vector<int> vTarget;
    //提前给目标容器分配空间
    vTarget.resize(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}