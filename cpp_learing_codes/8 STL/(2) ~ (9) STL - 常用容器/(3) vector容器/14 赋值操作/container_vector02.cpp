#include <iostream>
using namespace std;

//vector容器-赋值操作


//函数原型:

//vector& operator=(const vector &vec);      //重载 = 运算符

//assign(beg, end);         //将 [beg, end) 区间中的数据拷贝赋值给本身

//assign(n, elem);          //将n个elem拷贝赋值给本身


#include <vector>

void printVector(vector<int> &v) {

    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    vector<int> v1;
    for (int i = 0; i < 10; i++) {

        v1.push_back(i);
    }

    printVector(v1);

    //赋值
    //operator=
    vector<int> v2;
    v2 = v1;

    printVector(v2);

    //assign
    vector<int> v3;
    v3.assign(v2.begin(), v2.end());

    printVector(v3);

    //n个elem方式赋值
    vector<int> v4;
    v4.assign(10, 100);

    printVector(v4);
}


int main() {

    test01();

    system("pause");

    return 0;
}
