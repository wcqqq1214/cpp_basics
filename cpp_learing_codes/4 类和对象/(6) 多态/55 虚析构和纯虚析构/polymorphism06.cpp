#include <iostream>
using namespace std;

//多态-虚析构和纯虚析构

//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用子类的析构代码
//解决方式：将父类中的析构函数改为 虚析构 或 纯虚析构

//虚析构和纯虚析构的共性：
//1. 可以解决父类指针释放子类对象
//2. 都需要有具体的函数实现 (纯虚析构在类外实现)

// (如果有了纯虚析构，该类属于抽象类，无法实例化对象)

//虚析构语法：
//virtual ~类名() {}

//纯虚析构语法：
//virtual ~类名() = 0;
//类名::~类名() {}


class Animal {

public:

    string* m_Name;

    Animal() {
        cout << "Animal 构造函数调用" << '\n';
    }    

    //纯虚函数
    virtual void speak() = 0;

    //虚析构
    // virtual ~Animal() {
    //     cout << "Animal 虚析构调用" << '\n';
    // }

    //纯虚析构 (此处相当于函数声明)
    virtual ~Animal() = 0;  
};

//纯虚析构的具体实现
Animal::~Animal() {
    cout << "Animal 纯虚析构调用" << '\n';
}

class Cat: public Animal {

public:

    Cat(string name) {
        cout << "Cat 构造函数调用" << '\n';
        m_Name = new string(name);
    }

    void speak() {
        cout << *m_Name << "小猫在说话" << '\n';
    }

    ~Cat() {
        if (m_Name != NULL) {
            cout << "Cat 析构函数调用" << '\n';
            delete m_Name;
            m_Name = NULL;
        }
    }
};

void test01() {

    Animal* animal = new Cat("Tom");
    animal->speak();
    //父类指针在析构时候，不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏
    //利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    delete animal;
}


//总结：
//1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
//2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
//3. 拥有纯虚析构函数的类也属于抽象类


int main() {

    test01();

    system("pause");

    return 0;
}