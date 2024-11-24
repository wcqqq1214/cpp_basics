#include <iostream>
using namespace std;

//静态成员变量

//就是在成员变量和成员函数前加上关键字static

//1. 静态成员变量: 
class Person {

public:

    //(1) 所有对象共享同一份数据
    //(2) 在编译阶段分配内存
    //(3) 类内声明，类外初始化
    static int m_A;

    //静态成员变量也是有访问权限的
private:

    static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 100;

void test01() {

    Person p1;
    cout << "p1.m_A = " << p1.m_A << '\n';  //100

    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << '\n';  //200
    cout << "p2.m_A = " << p2.m_A << '\n';  //200
}

void test02() {

    //静态成员变量 不属于某个对象上，所有对象都共享同一份数据
    //因此静态成员变量有两种访问方式

    //1. 通过对象进行访问
    // Person p;
    // cout << p.m_A << '\n';

    //2. 通过类名进行访问
    cout << "m_A = "<< Person::m_A << '\n';

    // cout << "m_B = " << Person::m_B << '\n';     //类外访问不到私有静态成员变量
}

int main() {

    // test01();
    test02();

    system("pause");

    return 0;
}