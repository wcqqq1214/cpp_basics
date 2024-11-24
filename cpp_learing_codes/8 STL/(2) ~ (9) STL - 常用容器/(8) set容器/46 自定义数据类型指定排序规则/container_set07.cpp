#include <iostream>
using namespace std;
#include <set>

//set容器-自定义数据类型指定排序规则


//利用仿函数, 可以改变排序规则


class Person {

public:

    Person(string name, int age) {

        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class MyCompare {

public:

    bool operator()(const Person &p1, const Person &p2) {
        //按照年龄降序
        return p1.m_Age > p2.m_Age;
    }
};

void test01() {

    //自定义数据类型, 必须指定排序规则
    set<Person, MyCompare> s;

    //创建Person对象
    Person p1("Tom", 24);
    Person p2("Jerry", 14);
    Person p3("Donk", 17);
    Person p4("S1mple", 26);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (auto it = s.begin(); it != s.end(); it++) {

        cout << "name = " << it->m_Name << "\tage = " << it->m_Age << '\n';
    }
}

int main() {

    test01();

    system("pause");

    return 0;
}