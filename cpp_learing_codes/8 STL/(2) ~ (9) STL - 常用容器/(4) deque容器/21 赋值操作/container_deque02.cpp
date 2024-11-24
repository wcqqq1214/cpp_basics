#include <iostream>
using namespace std;
#include <deque>

//deque容器-赋值操作 (deque赋值操作与vector相同)


//函数原型:

//deque& operator=(const deque &deq);   //重载 = 操作符

//assign(beg, end);                     //将 [beg, end) 区间中的数据拷贝赋值给本身

//assign(n, elem);                      //将n个elem拷贝赋值给本身


void printDeque(const deque<int> &deq) {

    for (auto it = deq.begin(); it != deq.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    deque<int> d1;
    for (int i = 0; i < 10; i++) {

        d1.push_back(i);
    }
    printDeque(d1);

    // = 赋值
    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    //assign 赋值
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}


int main() {

    test01();

    system("pause");

    return 0;
}
