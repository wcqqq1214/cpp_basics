#include <iostream>
using namespace std;

//模板-类模板与继承


//当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型

//如果不指定，编译器无法给子类分配内存

//如果想灵活指定出父类中T的类型 ，子类也需变为类模板


template<class T>
class Base {

    T m;
};

//class Son: public Base {};    //错误，C++编译器需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son1: public Base<int> {   //必须指定一个类型  

};

void test01() {

    Son1 s1;
}


//如果想灵活指定出父类中T的类型 ，子类也需变为类模板
template<class T1, class T2>
class Son2: public Base<T2> {   //传入时，T2指定了父类的数据类型

    T1 obj;
};

void test02() {

    Son2<int, char> s2;
}

int main() {

    test01();
    
    system("pause");

    return 0;
}