#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//谓词-二元谓词


//如果operator()接受两个参数, 那么叫做二元谓词

class MyCompare {

public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test01() {

    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    //默认从小到大排序
    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';

    //使用函数对象  改变算法策略, 变排序规则为从大到小
    sort(v.begin(), v.end(), MyCompare());

    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}