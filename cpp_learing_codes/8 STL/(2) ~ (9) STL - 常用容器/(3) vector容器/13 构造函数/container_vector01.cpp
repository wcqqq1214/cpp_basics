#include <iostream>
using namespace std;

//(可变长数组)
//vector容器-构造函数


//功能: 
//vector数据结构和数组非常相似, 也称为单端数组

//vector与普通数组区别: 
//不同之处在于数组是静态空间, 而vector可以动态扩展

//动态扩展:
//并不是在原空间之后续接新空间, 而是找更大的内存空间, 然后将原数据拷贝新空间, 释放原空间


//函数原型:

//vector<T> v;                  //采用模板实现类实现, 默认构造函数

//vector(v.begin(), v.end());   //将 v [ begin(), end() ) 区间中的元素拷贝给本身    (左闭右开)

//vector(n, elem);              //构造函数将n个elem拷贝给本身 

//vector(const vector &vec);    //拷贝构造函数


#include <vector>

void printVector(vector<int> &v) {

    //auto 关键字 用于自动推导变量的类型    (可以用来替代迭代器的显式定义)
    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    //默认构造  无参构造
    vector<int> v1; 

    for (int i = 0; i < 10; i++) {
        
        v1.push_back(i);
    }

    printVector(v1);

    //通过区间的方式进行构造
    vector<int> v2(v1.begin(), v1.end());

    printVector(v2);

    //n个elem方式进行构造
    vector<int> v3(10, 100);

    printVector(v3);

    //拷贝构造
    vector<int> v4(v3);

    printVector(v4);
}


int main() {

    test01();    

    system("pause");

    return 0;
}
