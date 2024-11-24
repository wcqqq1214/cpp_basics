#include <iostream>
using namespace std;

//类作友元

class Building;

class GoodGay {

public:

    Building* building;

    GoodGay();

    void visit();   //参观函数  访问Building中的属性

};

class Building {

    //GoodGay类是本类的友元，可以访问本类的私有成员
    friend class GoodGay;

public:
    string m_SittingRoom;   //客厅

private:
    string m_BedRoom;   //卧室

public:
    Building();

};

//类外写成员函数
Building::Building() {

    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay() {

    //创建建筑物对象
    building = new Building;
}

void GoodGay::visit() {

    cout << "好朋友类正在访问: " << building->m_SittingRoom << '\n';

    cout << "好朋友类正在访问: " << building->m_BedRoom << '\n';
}

void test01() {

    GoodGay gg;
    gg.visit();
}

int main() {

    test01();

    system("pause");

    return 0;
}