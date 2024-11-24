#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法:

//算法简介:

//find              //查找元素

//find_if           //按条件查找元素

//adjacent_find     //查找相邻重复元素

//binary_search     //二分查找法

//count             //统计元素个数

//count_if          //按条件统计元素个数



//常用查找算法-find 

//功能:
//查找指定元素, 找到返回指定元素的迭代器, 找不到返回结束迭代器end()


//函数原型:
//find(iterator beg, iterator end, value);
//按值查找元素, 找到返回指定位置的迭代器, 找不到返回结束迭代器位置
//beg   开始迭代器
//end   结束迭代器
//value 查找的元素


//查找  内置数据类型
void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    //查找容器中是否有5这个元素  
    auto pos = find(v.begin(), v.end(), 5);

    if (pos == v.end()) {

        cout << "未找到该元素" << '\n';
    }
    else {

        cout << "找到该元素为: " << *pos << '\n';
    }
}

class Person {

public:
    Person(string name, int age) {
        
        this->m_Name = name;
        this->m_Age = age;
    }

    //重载 == 操作符, 让find的底层代码知道如何对比Person数据类型
    bool operator==(const Person &p) {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        }
        else {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

//查找  自定义数据类型
void test02() {

    vector<Person> v;
    
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    //放入到容器中s
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("bbb", 20);

    auto pos = find(v.begin(), v.end(), pp);    //查找容器中是否有与pp相同的元素

    if (pos == v.end()) {

        cout << "未找到该元素" << '\n';
    }
    else {

        cout << "找到该元素: name = " << pos->m_Name << " age = " << pos->m_Age << '\n';
    }
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}