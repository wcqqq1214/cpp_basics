#include <iostream>
using namespace std;
#include <functional>   //内建函数对象头文件

//内建函数对象-算术仿函数


//概念:
//STL内建了一些函数对象

//分类:
//算术仿函数
//关系仿函数
//逻辑仿函数

//用法:
//这些仿函数所产生的对象, 用法和一般函数完全相同
//使用内建函数对象, 需要引入头文件 #include <functional>



//算术仿函数:

//功能:
//实现四则运算
//其中negate是一元运算, 其他都是二元运算

//仿函数原型:

//template<class T> T plus<T>       //加法仿函数

//template<class T> T minus<T>      //减法仿函数

//template<class T> T multiplies<T> //乘法仿函数

//template<class T> T divides<T>    //除法仿函数

//template<class T> T modulus<T>    //取模仿函数

//template<class T> T negate<T>     //取反仿函数



//negate   一元仿函数   取反
void test01() {

    negate<int> n;

    cout << n(50) << '\n';
}

//plus  二元仿函数  加法
void test02() {

    plus<int> p;    // <> 内只需要传入一种数据类型

    cout << p(10, 20) << '\n';
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}