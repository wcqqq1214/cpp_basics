#include <iostream>
using namespace std;

//封装-访问权限

//3种权限
//公共权限  public      成员 类内可以访问    类外可以访问
//保护权限  protected   成员 类内可以访问    类外不可以访问 (子类可以访问父类)
//私有权限  private     成员 类内可以访问    类外不可以访问

class Person {

public:
    //公共权限
    string m_Name;

protected:
    //保护权限
    string m_Car;

private:
    //私有权限
    int m_Password;

};

int main() {

    

    system("pause");

    return 0;
}