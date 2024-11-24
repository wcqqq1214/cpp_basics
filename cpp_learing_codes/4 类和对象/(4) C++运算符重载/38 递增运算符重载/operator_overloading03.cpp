#include <iostream>
using namespace std;

//运算符重载 —— 递增运算符重载

//总结：前置递增返回引用，后置递增返回引用


//自定义整型
class MyInteger {

    friend ostream& operator<<(ostream &cout, const MyInteger &myint);

private:
    int m_Num;

public:

    MyInteger() {
        m_Num = 0;
    }

    //重载 前置++运算符 ++myint
    // (返回引用是为了一直对一个数据进行递增操作)
    MyInteger& operator++() {

        //先进行++运算
        m_Num++;
        
        //再将自身作返回 
        return *this;
    }


    //重载 后置++运算符 myint++
    //int代表占位参数，可以用于区分前置和后置递增 (！！！)
    // (后置递增返回值  而不是引用) => temp是局部对象 当前函数执行完后会被释放  若再返回temp的引用则是非法操作
    MyInteger operator++(int) {
        
        //先 记录当时结果
        MyInteger temp = *this;

        //后 递增
        this->m_Num++;

        //最后 将记录结果返回
        return temp;
    }

};

ostream& operator<<(ostream &cout, const MyInteger &myint) {

    cout << myint.m_Num;
    return cout;
}

void test01() {

    MyInteger myint;
    cout << myint << '\n';  //0

    cout << ++myint << '\n';    //1

}

void test02() {

    MyInteger myint;

    cout << myint++ << '\n';    //0

    cout << myint << '\n';  //1
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}