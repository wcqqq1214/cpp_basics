#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

//算法简介:

//sort              //对容器内元素进行排序 

//random_shuffle    //洗牌  指定范围内的元素随机调整次序

//merge             //容器元素合并, 并存储到另一容器中

//reverse           //反转指定范围内的元素



//常用排序算法-sort


//函数原型:

//sort(iterator beg, iterator end, _Pred);

//beg   开始迭代器
//end   结束迭代器
//_Pred 函数或者谓词(返回bool类型的仿函数)


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v;

    v.push_back(10);    
    v.push_back(30);    
    v.push_back(50);    
    v.push_back(20);    
    v.push_back(40);    

    //利用sort进行 升序
    sort(v.begin(), v.end());

    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';

    //改变为 降序
    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}