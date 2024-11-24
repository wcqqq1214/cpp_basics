#include <iostream>
using namespace std;
#include <map>

//map容器-排序 (默认排序: 按照key值进行 从小到大排序)


//利用仿函数, 改变排序规则

//对于自定义数据类型, map必须要指定排序规则, 同set容器


class MyCompare {

public:
    bool operator()(int v1, int v2) {
        //降序
        return v1 > v2;
    }
};

void test01() {

    //默认从小到大排序 (按照key值排序)
    //利用仿函数实现从大到小排序
    map<int, int, MyCompare> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));

    for (auto it = m.begin(); it != m.end(); it++) {

        cout << "key = " << it->first << " value = " << it->second << '\n';
    }
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}