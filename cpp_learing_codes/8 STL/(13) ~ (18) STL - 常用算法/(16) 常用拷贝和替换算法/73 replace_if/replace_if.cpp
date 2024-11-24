#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法-replace_if


//功能:
//将区间内满足条件的元素, 替换成指定元素


//函数原型:
//replace_if(iterator beg, iterator end, _pred, newvalue);

//beg       开始迭代器
//end       结束迭代器
//_pred     谓词
//newvalue  替换的新元素


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

class Greater5 {

public:
    bool operator()(int val) {
        return val > 5;
    }
};

void test01() {

    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    cout << "替换前: " << '\n';
    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';

    //把 大于5的数 替换为 100
    replace_if(v.begin(), v.end(), Greater5(), 100);

    cout << "替换后: " << '\n';
    for_each(v.begin(), v.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}