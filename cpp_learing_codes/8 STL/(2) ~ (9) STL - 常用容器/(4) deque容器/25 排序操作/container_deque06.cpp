#include <iostream>
using namespace std;

#include <deque>
#include <algorithm>    //标准算法头文件

//deque容器-排序操作 (利用算法实现对deque容器进行排序)


//算法:

//sort(iterator beg, iterator end);     //对beg和end区间内元素进行排序


void printDeque(const deque<int> &deq) {

    for (auto it = deq.begin(); it != deq.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //300 200 100 10 20 30
    printDeque(d);

    //排序 (默认排序规则: 从小到大 升序)
    //对于支持随机访问迭代器的容器, 都可以使用sort算法直接对其进行排序 (vector容器也可以使用sort排序)
    sort(d.begin(), d.end());   //需要包含算法头文件 #include <algorithm>

    //10 20 30 100 200 300
    printDeque(d);
}


int main() {

    test01();

    system("pause");

    return 0;
}
