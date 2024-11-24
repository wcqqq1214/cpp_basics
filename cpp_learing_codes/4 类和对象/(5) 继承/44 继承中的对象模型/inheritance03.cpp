#include <iostream>
using namespace std;

//继承-继承中的对象模型
class Base {

public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;    //私有成员只是被编译器隐藏了  但是还是会继承下去
};

//公共继承
class Son: public Base {

public:
    int m_D;
};

void test01() {

    //父类中所有非静态成员属性都会被子类继承下去
    cout << "sizeof Son = " << sizeof(Son) << '\n'; //16
}



int main() {

    test01();

    system("pause");

    return 0;
}