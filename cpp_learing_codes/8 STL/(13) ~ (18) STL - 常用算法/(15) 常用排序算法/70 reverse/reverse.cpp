#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用排序算法-reverse


//功能:
//将容器内元素进行反转


//函数原型:
//reverse(iterator beg, iterator end);

//beg   开始迭代器
//end   结束迭代器


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }    

    cout << "反转前: " << '\n';
    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';

    reverse(v.begin(), v.end());

    cout << "反转后: " << '\n';
    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}