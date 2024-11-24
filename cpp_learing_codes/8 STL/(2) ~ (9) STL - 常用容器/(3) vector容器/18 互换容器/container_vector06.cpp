#include <iostream>
using namespace std;
#include <vector>

//vector容器-互换容器 (实现两个容器内元素进行互换)


//函数原型:

//swap(vec);    //将vec与本身的元素互换


void printVector(vector<int> &vec) {

    for (auto it = vec.begin(); it != vec.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}


//1. 基本使用
void test01() {

    vector<int> v1;
    for (int i = 0; i < 10; i++) {

        v1.push_back(i);
    }

    cout << "交换前: " << '\n';
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--) {

        v2.push_back(i);
    }

    printVector(v2);


    cout << "交换后: " << '\n';

    v1.swap(v2);

    printVector(v1);
    printVector(v2);
}

//2. 实际用途
//巧用swap可以收缩内存空间
void test02() {

    vector<int> v;
    for (int i = 0; i < 1e5; i++) {

        v.push_back(i);
    }

    cout << "v的容量: " << v.capacity() << '\n';
    cout << "v的大小: " << v.size() << '\n';

    v.resize(3);    //重新指定大小

    cout << "v的容量: " << v.capacity() << '\n';
    cout << "v的大小: " << v.size() << '\n';

    vector<int> (v).swap(v);    //巧用swap可以收缩内存空间
    //vector<int> (v)   //调用拷贝构造函数 利用v 创建的 匿名对象 (根据v的size初始化匿名对象)
    //.swap(v)      //相当于指针互换, 把 指向匿名对象的指针 和 指向v的指针 互换, 而匿名对象执行完这段代码后被销毁  

    cout << "v的容量: " << v.capacity() << '\n';
    cout << "v的大小: " << v.size() << '\n';
}


int main() {

    // test01();

    test02();

    system("pause");

    return 0;
}
