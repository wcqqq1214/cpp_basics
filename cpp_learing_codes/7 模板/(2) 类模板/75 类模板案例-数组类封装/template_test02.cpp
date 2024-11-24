#include <iostream>
using namespace std;

//模板-类模板案例-数组类封装


//案例描述: 实现一个通用的数组类，要求如下:

//1. 可以对内置数据类型以及自定义数据类型的数据进行存储
//2. 将数组中的数据存储到堆区
//3. 构造函数中可以传入数组的容量
//4. 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//5. 提供尾插法和尾删法对数组中的数据进行增加和删除
//6. 可以通过下标的方式访问数组中的元素
//7. 可以获取数组中当前元素个数和数组的容量

#include "MyArray.hpp"


void printIntArray(MyArray<int> &arr) {

    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
}

void test01() {

    MyArray<int> arr1(5);
    
    for (int i = 0; i < 5; i++) {

        //利用尾插法向数组中插入数据
        arr1.Push_Back(i);
    }

    cout << "arr1的打印输出为: " << '\n';

    printIntArray(arr1);

    cout << '\n';

    cout << "arr1的容量为: " << arr1.getCapacity() << '\n';

    cout << "arr1的大小为: " << arr1.getSize() << '\n';


    MyArray<int> arr2(arr1);

    cout << "arr2的打印输出为: " << '\n';

    printIntArray(arr2);

    cout << '\n';

    //尾删法
    arr2.Pop_Back();

    cout << "arr2尾删后: " << '\n';

    cout << "arr2的容量为: " << arr2.getCapacity() << '\n';

    cout << "arr2的大小为: " << arr2.getSize() << '\n';
}


//测试自定义数据类型
class Person {

public:

    Person() {

        this->m_Name = "Unknown";
        this->m_Age = 0;
    }

    Person(string name, int age) {

        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr) {

    for (int i = 0; i < arr.getSize(); i++) {

        cout << "姓名: " << arr[i].m_Name  << " 年龄: " << arr[i].m_Age << '\n';
        cout << '\n'; 
    }
}

void test02() {

    MyArray<Person> arr(10);

    Person p1("Tom", 20);
    Person p2("Jerry", 19);
    Person p3("Jame", 23);
    Person p4("Donk", 17);
    Person p5("S1mple", 25);

    //将数组插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    //打印数组
    printPersonArray(arr);

    //输出容量和大小
    cout << "数组容量为: " << arr.getCapacity() << '\n';

    cout << "数组大小为: " << arr.getSize() << '\n';
}

int main() {

    // test01();

    test02();
    
    system("pause");

    return 0;
}