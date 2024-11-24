#include <iostream>
using namespace std;

//myint--   --myint

class MyInteger {

    friend ostream& operator<<(ostream &cout, const MyInteger &myint);

private:

    int m_Num;

public:

    MyInteger() {
        m_Num = 0;
    }

    //前置--    --myint
    MyInteger& operator--() {

        this->m_Num--;

        return *this;
    }

    //后置--    myint--
    MyInteger operator--(int) {

        MyInteger temp;

        this->m_Num--;

        return temp;
    }

};

ostream& operator<<(ostream &cout, const MyInteger &myint) {

    cout << myint.m_Num;
    return cout;
}

void test01() {

    MyInteger myint;
    cout << myint << '\n';  //0

    cout << --myint << '\n';    //-1
}

void test02() {

    MyInteger myint;
    cout << myint-- << '\n';    //0

    cout << myint << '\n';  //-1
}

int main() {

    test01();   //--myint

    test02();   //myint--

    system("pause");

    return 0;
}