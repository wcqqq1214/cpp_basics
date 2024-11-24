#include <iostream>
using namespace std;

//继承-构造和析构顺序


//子类继承父类后，当创建子类对象时，也会调用父类的构造函数
class Base {

public:
    Base() {
        cout << "Base 构造函数调用" << '\n';
    }

    ~Base() {
        cout << "Base 析构函数调用" << '\n';
    }
};

class Son: public Base {

public:
    Son() {
        cout << "Son 构造函数调用" << '\n';
    }

    ~Son() {
        cout << "Son 析构函数调用" << '\n';
    }
};

void test01() {
    
    //继承中的构造和析构顺序如下：
    //先构造父类，再构造子类，析构的顺序与构造的顺序相反
    Son s1;
}

int main() {

    test01();   

    system("pause");

    return 0;
}