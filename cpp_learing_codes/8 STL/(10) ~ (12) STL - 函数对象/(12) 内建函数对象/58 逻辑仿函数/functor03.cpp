#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>

//内建函数对象-逻辑仿函数   (实际开发中很少用得到)


//功能:
//实现逻辑运算


//函数原型:

//template<class T> bool logical_and<T>     //逻辑与

//template<class T> bool logical_or<T>      //逻辑或

//template<class T> bool logical_not<T>     //逻辑非


//逻辑非    logical_not
void test01() {

    vector<bool> v1;

    v1.push_back(true);
    v1.push_back(false);
    v1.push_back(true);
    v1.push_back(false);

    for (auto it = v1.begin(); it != v1.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';

    //利用逻辑非    将容器v1 搬运到 容器v2中, 并执行取反操作
    vector<bool> v2;
    v2.resize(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());

    for (auto it = v2.begin(); it != v2.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}