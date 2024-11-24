#include <iostream>
using namespace std;

//封装-案例-设计学生类
class Student {

public:
    string m_Name;
    string m_Id;

    //显示姓名和学号
    void showStudent() {   
        cout << "姓名：" << m_Name << '\t' << "学号：" << m_Id << '\n';
    }
};

int main() {

    Student s1;
    s1.m_Name = "wcq";
    s1.m_Id = "123456";
    
    s1.showStudent();

    system("pause");

    return 0;
}