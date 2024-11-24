#include <iostream>
using namespace std;

//封装-成员属性设置为私有
//1. 可以自己控制读写权限
//2. 对于写可以检测数据有效性

class Person {

private:
    string m_Name;  //可读可写

    int m_Age = 18;  //只读

    string m_Idol;  //只写

public:
    //设置姓名
    void setName(string name) {
        m_Name = name;
    }
    //获取姓名
    string getName() {
        return m_Name;
    }

    //获取年龄
    int getAge() {
        return m_Age;
    }

    //设置偶像
    void setIdol(string idol) {
        m_Idol = idol;
    }
};

int main() {

    Person p1;
    //姓名设置
    p1.setName("wcqqq");
    cout << "姓名：" << p1.getName() << '\n';

    //年龄设置
    cout << "年龄：" << p1.getAge() << '\n';

    //偶像设置
    p1.setIdol("cxk");

    system("pause");

    return 0;
}