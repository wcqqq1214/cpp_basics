#include <iostream>
using namespace std;

//模板-类模板分文件编写


//问题: 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

//解决:
//1. 直接包含.cpp源文件 (不要包含头文件person.h，直接包含源文件person.cpp)
// #include "person.cpp"

//2. 将声明和实现写到同一个文件中，并更改后缀名为.hpp (.hpp是约定的名称，并不是强制)    (常用！！！)
#include "person.hpp"


void test01() {

    Person<string, int> p("Jerry", 18);
    p.showPerson();
}


int main() {

    test01();
    
    system("pause");

    return 0;
}