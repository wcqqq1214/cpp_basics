#include <iostream>
using namespace std;

//类对象作为类成员

//C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员

class Phone {

public:

    //手机名称
    string m_PName;

    Phone(string pName) {
        m_PName = pName;
        cout << "Phone 构造函数调用" << '\n';
    }

    ~Phone() {
        cout << "Phone 析构函数调用" << '\n';
    }
};

class Person {

public:

    //姓名
    string m_Name;
    //手机
    Phone m_Phone;

    //相当于 Phone m_Phone = pName; 隐式转换法
    Person(string name, string pName): m_Name(name), m_Phone(pName) {
        cout << "Person 构造函数调用" << '\n';
    }

    ~Person() {
        cout << "Person 析构函数调用" << '\n';
    }
};

//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
//ps：析构的顺序与构造相反
void test01() {
    Person p("wcq", "iphone13");
    cout << "姓名: " << p.m_Name << "  手机名称: " << p.m_Phone.m_PName << '\n';
}

int main() {

    test01();   //先构造Phone对象，再构造Person对象

    system("pause");

    return 0;
}