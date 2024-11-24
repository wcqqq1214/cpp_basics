#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用遍历算法-transform    (搬运容器到另一个容器中)


//函数原型:

//transform(iterator beg1, iterator end1, iterator beg2, _func);

//beg1  源容器开始迭代器
//end1  源容器结束迭代器
//beg2  目标容器开始迭代器
//_func 函数或者函数对象

//总结: 搬运的目标容器必须要提前开辟空间, 否则无法正常搬运


class Transform {

public:
    int operator()(int val) {
        return val + 100;
    }
};

class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v;      //源容器
    for (int i = 0; i < 10; i++) {
        
        v.push_back(i);
    }    

    vector<int> vTarget;        //目标容器
    vTarget.resize(v.size());   //目标容器 需要提前开辟空间

    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}