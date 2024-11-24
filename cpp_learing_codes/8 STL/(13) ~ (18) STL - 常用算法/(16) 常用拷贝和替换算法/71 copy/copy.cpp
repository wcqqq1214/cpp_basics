#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法-copy


//算法简介:

//copy              //容器内指定范围的元素拷贝到另一容器中

//replace           //将容器内指定范围的旧元素替换为新元素

//replace_if        //将容器内指定范围满足条件的元素替换为新元素

//swap              //互换两个容器的元素



//函数原型:

//copy(iterator beg, iterator end, iterator dest);

//beg   开始迭代器
//end   结束迭代器
//dest  目标容器起始迭代器


void myPrint(int val) {

    cout << val << " ";
}

void test01() {

    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int> v2;
    //提前给目标容器开辟空间
    v2.resize(v1.size());

    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myPrint);
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}