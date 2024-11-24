#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法-count


//功能:
//统计元素个数


//函数原型:
//count(iterator beg, iterator end, value);

//beg   开始迭代器
//end   结束迭代器
//value 统计的元素


//ps: 统计自定义数据类型, 需要配合重载 operator==


//统计  内置数据类型
void test01() {

    vector<int> v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);

    cout << "元素40的个数为: " << num << '\n';
}

//统计  自定义数据类型
class Person {

public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    bool operator==(const Person &p) {
        if (this->m_Age == p.m_Age) {
            return true;
        }
        else {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

void test02() {

    vector<Person> v;

    Person p1("Donk", 17);
    Person p2("Jame", 17);
    Person p3("Tom", 17);
    Person p4("Jerry", 30);
    Person p5("b1t", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("Smith", 17);

    //查找与Smith年龄相同的人有几个
    int num = count(v.begin(), v.end(), p);

    cout << "与Smith年龄相同的人数为: " << num << '\n';
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}