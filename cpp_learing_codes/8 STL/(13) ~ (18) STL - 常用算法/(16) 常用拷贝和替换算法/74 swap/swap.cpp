#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法-swap


//功能:
//互换两个容器的元素


//函数原型:

//swap(container c1, container c2);

//c1    容器1
//c2    容器2

//ps: 必须是同种类型的容器才能进行交换!!


class MyPrint {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 6; i++) {

        v1.push_back(i);
        v2.push_back(i + 100);
    }
    
    cout << "交换前: " << '\n';
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << '\n';

    for_each(v2.begin(), v2.end(), MyPrint());
    cout << '\n';

    //交换两个容器的元素
    swap(v1, v2);

    cout << "交换后: " << '\n';
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << '\n';

    for_each(v2.begin(), v2.end(), MyPrint());
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}