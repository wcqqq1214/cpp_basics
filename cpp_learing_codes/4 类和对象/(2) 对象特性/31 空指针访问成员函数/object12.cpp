#include <iostream>
using namespace std;

//空指针访问成员函数

class Person {

public:

    int m_Age = 20;

    void showClassName() {

        cout << "this is Person class" << '\n';
    }

    void showPersonAge() {

        //报错的原因是因为传入的指针是NULL

        if (this == NULL) return;

        cout << "age = " << this->m_Age << '\n';
    }

};

void test01() {

    Person *p = NULL;

    p->showClassName();

    p->showPersonAge();
}

int main() {

    test01();


    system("pause");

    return 0;
}