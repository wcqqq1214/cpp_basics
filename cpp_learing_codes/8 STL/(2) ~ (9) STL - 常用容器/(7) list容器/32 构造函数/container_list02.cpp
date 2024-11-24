#include <iostream>
using namespace std;
#include <list>

//list容器-构造函数


//函数原型:

//list<T> lst;              //采用模板类实现, 默认构造形式

//list(beg, end);           //构造函数将 [beg, end) 区间中的元素拷贝给本身

//list(n, elem);            //构造函数将n个elem拷贝给本身

//list(const list &lst);    //拷贝构造函数


void printList(const list<int> &L) {

    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    //创建list容器
    list<int> L1;   //默认构造

    //添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //遍历容器
    printList(L1);


    //区间方式构造
    list<int> L2(L1.begin(), L1.end());

    printList(L2);

    //拷贝构造
    list<int> L3(L2);

    printList(L3);

    //n个elem
    list<int> L4(10, 100);

    printList(L4);
}

int main() {

    test01();

    system("pause");

    return 0;
}