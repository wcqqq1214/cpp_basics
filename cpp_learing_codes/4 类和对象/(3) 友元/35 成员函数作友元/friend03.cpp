#include <iostream>
using namespace std;

//成员函数做友元

class Building;

class GoodGay {

public:

    Building* building;

    GoodGay();

    void visit();    //让visit()函数可以访问Building中私有成员
    
};

class Building {

    //告诉编译器   GoodGay类下的visit()成员函数作为本类的友元，可以访问私有成员
    friend void GoodGay::visit();

public:
    string m_SittingRoom;   //客厅

private:
    string m_BedRoom;   //卧室

public:
    Building();

};

//类外实现成员函数
Building::Building() {

    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay() {

    building = new Building;
}

void GoodGay::visit() {

    cout << "visit()函数 正在访问: " << building->m_SittingRoom << '\n';
    
    cout << "visit()函数 正在访问: " << building->m_BedRoom << '\n';
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