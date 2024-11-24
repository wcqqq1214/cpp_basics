#include <iostream>
using namespace std;
#include <map>

//map容器-查找和统计


//函数原型:

//find(key);            //查找key是否存在, 若存在, 返回该键的元素的迭代器; 若不存在, 返回map.end()

//count(key);           //统计key的元素个数


void test01() {

    map<int, int> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));

    //查找
    //map<int, int>::iterator pos = m.find(3);
    auto pos = m.find(3);

    if (pos != m.end()) {

        cout << "找到该元素 key = " << pos->first << " value = " << pos->second << '\n';
    }
    else {

        cout << "未找到该元素" << '\n';
    }

    //统计
    //map不允许插入重复key元素, count统计的结果只能为0或1 
    int num = m.count(3);
    cout << "num = " << num << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}