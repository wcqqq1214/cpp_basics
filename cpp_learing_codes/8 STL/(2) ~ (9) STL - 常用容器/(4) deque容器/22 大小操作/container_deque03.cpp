#include <iostream>
using namespace std;
#include <deque>

//deque容器-大小操作


//函数原型:

//deque.empty();            //判断容器是否为空

//deque.size();             //返回容器中元素的个数

//deque.resize(num);        //重新指定容器的长度为nun, 若容器变长, 则以默认值0填充新位置
                            //如果容器变短, 则末尾超出容器长度的元素被删除

//deque.resize(num, elem);  //重新指定容器的长度为nun, 若容器变长, 则以elem值填充新位置
                            //如果容器变短, 则末尾超出容器长度的元素被删除 


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

    if (d1.empty()) {

        cout << "d1为空" << '\n';
    }
    else {

        cout << "d1不为空" << '\n';
        cout << "d1的大小: " << d1.size() << '\n';  //统计大小
        //deque容器没有容量概念
    }

    //重新指定大小
    // d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}


int main() {

    test01();

    system("pause");

    return 0;
}
