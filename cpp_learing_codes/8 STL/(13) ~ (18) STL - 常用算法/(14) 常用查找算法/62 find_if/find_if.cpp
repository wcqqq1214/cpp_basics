#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法-find_if

//功能:
//按条件查找元素


//函数原型:

//find_if(iterator beg, iterator end, _Pred);
//按条件查找元素, 找到返回指定位置迭代器, 找不到返回结束迭代器位置
//beg   开始迭代器
//end   结束迭代器
//_Pred 函数或者谓词(返回bool类型的仿函数)


//查找  内置数据类型
class GreaterFive {

public:
    bool operator()(int val) {
        return val > 5;
    }
};

void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    auto pos = find_if(v.begin(), v.end(), GreaterFive());

    if (pos == v.end()) {

        cout << "没有找到" << '\n';
    }
    else {

        cout << "找到大于5的数字为: " << *pos << '\n';
    }
}

//查找  自定义数据类型
class Person {

public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class AgeGreater20 {

public:
    bool operator()(const Person &p) {
        return p.m_Age > 20;
    }
};

void test02() {

    vector<Person> v;

    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    //把数据插入容器
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //找年龄大于20的人
    auto pos = find_if(v.begin(), v.end(), AgeGreater20());

    if (pos == v.end()) {

        cout << "没有找到" << '\n';
    }
    else {

        cout << "找到年龄大于20的人, name = " << pos->m_Name << " age = " << pos->m_Age << '\n';
    }
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}