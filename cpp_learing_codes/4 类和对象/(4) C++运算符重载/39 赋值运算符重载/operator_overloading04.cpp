#include <iostream>
using namespace std;

//运算符重载 —— 赋值运算符重载

//作用：解决深拷贝与浅拷贝的问题

//C++编译器至少给一个类添加4个函数
//1. 默认构造函数(无参, 函数体为空)
//2. 默认析构函数(无参, 函数体为空)
//3. 默认拷贝构造函数, 对属性进行值拷贝
//4. 赋值运算符 operator=, 对属性进行值拷贝

class Person {

public:

    int* m_Age;

    Person(int age) {

        m_Age = new int(age);
    }

    ~Person() {
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //重载 赋值运算符
    Person& operator=(const Person &p) {

        //先判断是否有属性在堆区，如果有，先释放干净，然后再进行深拷贝
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }

        //深拷贝
        this->m_Age = new int(*p.m_Age);

        //返回对象的本身
        return *this;
    }
};

void test01() {

    Person p1(18);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1;    //链式赋值操作

    cout << "p1的年龄为: " << *p1.m_Age << '\n';    //18

    cout << "p2的年龄为: " << *p2.m_Age << '\n';    //18

    cout << "p3的年龄为: " << *p3.m_Age << '\n';    //18
}

int main() {

    test01();

    system("pause");

    return 0;
}