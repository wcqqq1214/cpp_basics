#include <iostream>
using namespace std;
#include <set>

//set容器-内置类型指定排序规则


//利用仿函数, 可以改变排序规则 (默认排序规则为从小到大)


class MyCompare {

public:

    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test01() {

    set<int> s1;

    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);

    for (auto it = s1.begin(); it != s1.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n'; 

    //指定排序规则为从大到小 (在插入数据之前)

    set<int, MyCompare> s2;

    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);

    for (auto it = s2.begin(); it != s2.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}