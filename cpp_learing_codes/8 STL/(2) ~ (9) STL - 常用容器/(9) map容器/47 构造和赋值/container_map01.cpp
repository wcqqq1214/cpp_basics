#include <iostream>
using namespace std;
#include <map>

//(键值对容器)
//map容器-构造和赋值


//简介:
//1. map中所有元素都是pair
//2. pair中 第一个元素为 key (键值), 起到索引作用, 第二个元素为 value (实值)
//3. 所有元素都会根据元素的 key值 自动排序

//本质:
//map/multimap属于关联式容器, 底层结构是用二叉树实现

//优点:
//可以根据key值快速找到value值

//map和multimap区别:
//map不允许容器中有重复key值元素
//multimap允许容器中有重复key值元素


//函数原型:

//构造
//map<T1, T2> mp;               //map默认构造函数
//map(const map &mp);           //拷贝构造函数

//赋值
//map& operator=(const map &mp);    //重载 = 操作符


void printMap(const map<int, int> &m) {

    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++) {

        cout << "key = " << it->first << " value = " << it->second << '\n';
    }
    cout << '\n';
}

void test01() {

    //创建map容器
    map<int, int> m1;

    m1.insert(pair<int, int>(1, 10));    //相当于匿名对组
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));

    printMap(m1);

    //拷贝构造
    map<int, int> m2(m1);

    printMap(m2);

    //= 赋值
    map<int, int> m3;
    m3 = m2;

    printMap(m3);
}

int main() {

    test01();

    system("pause");

    return 0;
}