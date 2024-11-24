#include <iostream>
using namespace std;
#include <list>

//list容器-排序案例 (对于自定义数据类型)


//案例描述: 将Person自定义数据类型进行排序, Person中属性有姓名、年龄、身高

//排序规则: 按照年龄进行升序, 如果年龄相同按照身高进行降序


//ps: 对于自定义数据类型, 必须要指定排序规则, 否则编译器不知道如何进行排序

class Person {

public:

    Person(string name, int age, int height) {

        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;  //姓名
    int m_Age;      //年龄
    int m_Height;   //身高
};

//指定排序规则
bool comparePerson(const Person &p1, const Person &p2) {

    if (p1.m_Age == p2.m_Age) { //如果年龄相同按照身高进行 降序

        return p1.m_Height > p2.m_Height;
    }
    else {  //按照年龄进行 升序    
    
        return p1.m_Age < p2.m_Age;
    }
}

void test01() {

    list<Person> L; //创建容器

    //准备数据
    Person p1("Donk", 17, 63);
    Person p2("S1mple", 23, 70);
    Person p3("Jame", 26, 85);
    Person p4("Zywoo", 23, 65);
    Person p5("wcq", 23, 75);

    //插入数据
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);

    cout << "排序前: " << '\n';
    for (auto it = L.begin(); it != L.end(); it++) {

        cout << "name = " << it->m_Name 
            << "\tage = " << it->m_Age 
            << "\theight = " << it->m_Height << '\n';
    }

    //排序
    L.sort(comparePerson);

    cout << "排序后: " << '\n';
    for (auto it = L.begin(); it != L.end(); it++) {

        cout << "name = " << it->m_Name 
            << "\tage = " << it->m_Age 
            << "\theight = " << it->m_Height << '\n';
    }
}

int main() {

    test01();

    system("pause");

    return 0;
}