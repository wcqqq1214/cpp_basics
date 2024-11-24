#include <iostream>
using namespace std;

//继承-基本语法

//作用：减少重复代码
//语法： class 子类: 继承方式 父类 {};

//子类  也称为  派生类
//父类  也称为  基类


//公共页面类
class BasePage {

public:

    void header() {
        cout << "公共头部" << '\n';
    }

    void footer() {
        cout << "公共底部" << '\n';
    }

    void left() {
        cout << "左侧列表" << '\n';
    }

};

//Python页面
class Python: public BasePage {

public:

    void content() {
        cout << "Python视频" << '\n';
    }

};

void test01() {

    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
}

int main() {

    test01();

    system("pause");

    return 0;
}