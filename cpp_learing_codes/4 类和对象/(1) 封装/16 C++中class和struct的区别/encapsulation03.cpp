#include <iostream>
using namespace std;

//封装-C++中 class 和 struct 的区别

// (默认访问权限不同)
//struct 默认权限为公共
//class  默认权限为私有

class C1 {

    int m_A;    //默认是私有权限
};

struct C2 {

    int m_A;    //默认是公共权限
};

int main() {

    

    system("pause");

    return 0;
}