#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法-count_if


//功能:
//按条件统计元素个数


//函数原型:
//count_if(iterator beg, iterator end, _Pred);

//beg   开始迭代器
//end   结束迭代器
//_Pred 函数或者谓词(返回bool类型的仿函数)


//统计  内置数据类型
class Greater4 {

public:
    bool operator()(int val) {
        return val > 4;
    }
};

void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << '\n';

    int num = count_if(v.begin(), v.end(), Greater4());

    cout << "大于4的元素个数为: " << num << '\n';
}

//统计  自定义数据类型 
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

    Person p1("Tom", 35);
    Person p2("Jerry", 35);
    Person p3("Smith", 35);
    Person p4("Paul", 40);
    Person p5("Donk", 20);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //统计年龄大于20的人个数
    int num = count_if(v.begin(), v.end(), AgeGreater20());

    cout << "年龄大于20的人个数为: " << num << '\n';
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}