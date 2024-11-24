#include <iostream>
using namespace std;
#include <queue>

//queue容器-常用接口


//构造函数:
//queue<T> que;                 //queue采用模板类实现, queue对象的默认构造形式
//queue(const queue &que);      //拷贝构造函数

//赋值操作:
//queue& operator=(const queue &que);   //重载 = 操作符

//数据存取:
//push(elem);       //往队尾添加元素
//pop();            //从队头移除第一个元素
//back();           //返回最后一个元素
//front();          //返回第一个元素

//大小操作:
//empty();          //判断队列是否为空
//size();           //返回队列的大小


class Person {

public:

    Person(string name, int age) {

        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01() {

    //创建队列
    queue<Person> q;

    //准备数据
    Person p1("Tom", 19);
    Person p2("Jerry", 21);
    Person p3("Donk", 17);
    Person p4("S1mple", 26);

    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "队列大小: " << q.size() << '\n';

    //判断只要队列不为空, 查看队头, 查看队尾, 出队
    while (!q.empty()) {

        //查看队头
        cout << "队头元素: name = " << q.front().m_Name << "\tage = " << q.front().m_Age << '\n';

        //查看队尾
        cout << "队尾元素: name = " << q.back().m_Name << "\tage = " << q.back().m_Age << '\n';
        
        cout << '\n';

        //出队
        q.pop();
    }

    cout << "队列大小: " << q.size() << '\n';
}

int main() {

    test01();

    system("pause");

    return 0;
}