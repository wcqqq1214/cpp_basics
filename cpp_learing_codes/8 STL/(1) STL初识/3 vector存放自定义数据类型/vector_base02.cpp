#include <iostream>
using namespace std;

//vector存放自定义数据类型

#include <vector>

//自定义数据类型
class Person {

public:

    Person(string name, int age) {

        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//存放自定义数据类型
void test01() {

    vector<Person> v;

    Person p1("donk", 17);
    Person p2("Jame", 24);
    Person p3("S1mple", 25);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

        cout << "name = " << it->m_Name << "\tage = " << it->m_Age << '\n';
    }
}

//存放自定义数据类型的指针
void test02() {

    vector<Person*> v;

    Person p1("donk", 17);
    Person p2("Jame", 24);
    Person p3("S1mple", 25);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    //遍历容器中的数据
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {

        Person* p = (*it);
        cout << "name = " << p->m_Name << "\tage = " << (*it)->m_Age << '\n';
    }
}


int main() {

    // test01();

    test02();

    system("pause");

    return 0;
}