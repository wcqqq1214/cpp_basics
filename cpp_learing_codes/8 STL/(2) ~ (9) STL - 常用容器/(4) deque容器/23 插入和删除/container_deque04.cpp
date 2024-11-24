#include <iostream>
using namespace std;
#include <deque>

//deque容器-插入和删除


//函数原型:

//(两端操作):

//push_back(elem);      //在容器尾部添加一个数据

//push_front(elem);     //在容器头部插入一个数据

//pop_back();           //删除容器最后一个数据

//pop_front();          //删除容器第一个数据

//(指定位置操作):

//insert(pos, elem);        //在pos位置插入一个elem元素的拷贝, 返回新数据的位置

//insert(pos, n, elem);     //在pos位置插入n个elem数据, 无返回值

//insert(pos, beg, end);    //在pos位置插入 [beg, end) 区间的数据, 无返回值

//clear();                  //清空容器的所有数据

//erase(beg, end);          //删除 [beg, end) 区间的数据, 返回下一个数据的位置

//erase(pos);               //删除pos位置的数据, 返回下一个数据的位置

//ps: 如果有返回值，它们返回的都是迭代器


void printDeque(const deque<int> &deq) {

    for (auto it = deq.begin(); it != deq.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

//两端操作
void test01() {

    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);

    //200 100 10 20
    printDeque(d1);     


    //尾删
    d1.pop_back();

    //200 100 10
    printDeque(d1);


    //头删
    d1.pop_front();

    //100 10
    printDeque(d1);
}


//指定位置操作
void test02() {

    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);

    d1.push_front(100);
    d1.push_front(200);

    //200 100 10 20
    printDeque(d1);


    //insert插入
    d1.insert(d1.begin(), 1000);

    //1000 200 100 10 20
    printDeque(d1);

    d1.insert(d1.begin(), 2, 2000);

    //2000 2000 1000 200 100 10 20
    printDeque(d1);


    //按照区间插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());

    //1 2 3 2000 2000 1000 200 100 10 20
    printDeque(d1);
}

//删除操作
void test03() {

    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);

    d1.push_front(100);
    d1.push_front(200);
    //200 100 10 20

    //删除指定位置
    auto it = d1.begin();   //deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);   //删除第二个位置的元素

    //200 10 20
    printDeque(d1);

    //按区间方式删除
    // d1.erase(d1.begin(), d1.end());
    d1.clear();
    //清空
    printDeque(d1);
}

int main() {

    // test01();

    // test02();

    test03();

    system("pause");

    return 0;
}
