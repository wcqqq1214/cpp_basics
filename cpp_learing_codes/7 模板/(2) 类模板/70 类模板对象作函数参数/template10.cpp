#include <iostream>
using namespace std;

//模板-类模板对象作函数参数


//类模板实例化的对象，向函数传参的方式:

//1. 指定传入类型   ————直接显示对象的数据类型

//2. 参数模板化     ————将对象中的参数变为模板进行传递

//3. 整个类模板化   ————将这个对象类型模板化进行传递


//类模板
template<class NameType, class AgeType = int>
class Person {

public:

    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name = " << this->m_Name << '\n';
        cout << "age = " << this->m_Age << '\n';
    }

    NameType m_Name;
    AgeType m_Age;
};


//1. 指定传入类型   ————直接显示对象的数据类型  (最常用！！！)
void printPerson1(Person<string, int> &p) {

    p.showPerson();
}

void test01() {

    Person<string, int> p("Tom", 20);
    printPerson1(p);
}


//2. 参数模板化     ————将对象中的参数变为模板进行传递
template<class NameType, class AgeType>
void printPerson2(Person<NameType, AgeType> &p) {

    p.showPerson();
    cout << "NameType的类型为: " << typeid(NameType).name() << '\n';
    cout << "AgeType的类型为: " << typeid(AgeType).name() << '\n';
}

void test02() {

    Person<string, int> p("Jerry", 19);
    printPerson2(p);
}


//3. 整个类模板化   ————将这个对象类型模板化进行传递
template<class T>
void printPerson3(T &p) {

    p.showPerson();
    cout << "T的数据类型为: " << typeid(T).name() << '\n';
}

void test03() {

    Person<string, int> p("Jame", 21);
    printPerson3(p);
}


int main() {

    // test01();

    // test02();

    test03();
    
    system("pause");

    return 0;
}