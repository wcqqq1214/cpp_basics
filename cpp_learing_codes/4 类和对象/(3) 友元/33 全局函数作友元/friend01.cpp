#include <iostream>
using namespace std;

//全局函数做友元 (friend)

//友元的目的就是让一个函数或者类 访问另一个类中的私有成员

//友元的三种实现：
//1. 全局函数做友元
//2. 类做友元
//3. 成员函数做友元

 
//建筑物类
class Building {

    //全局函数做友元
    friend void goodGay(Building &building);

public:
    string m_SittingRoom;   //客厅

private:
    string m_BedRoom;   //卧室

public:

    Building() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }


};

//全局函数
void goodGay(Building &building) {

    cout << "好朋友全局函数 正在访问：" << building.m_SittingRoom << '\n';

    cout << "好朋友全局函数 正在访问：" << building.m_BedRoom << '\n';
}

void test01() {

    Building building;
    goodGay(building);
}

int main() {

    test01();    

    system("pause");

    return 0;
}