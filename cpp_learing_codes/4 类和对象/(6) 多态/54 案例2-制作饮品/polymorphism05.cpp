#include <iostream>
using namespace std;

//多态-案例2-制作饮品

//制作饮品的大致流程为：煮水 -> 冲泡 -> 倒入杯中 -> 加入辅料

//冲咖啡：
//煮水 -> 冲泡咖啡 -> 倒入杯中 -> 加入糖和牛奶

//冲茶叶：
//煮水 -> 冲泡茶叶 -> 倒入杯中 -> 加入柠檬


class AbstractMakeDrink {

public:

    //煮水
    void boilWater() {
        cout << "煮水" << '\n';
    }

    //冲泡
    virtual void brew() = 0;

    //倒入杯中
    void pourIntoCup() {
        cout << "倒入杯中" << '\n';
    }

    //加入辅料
    virtual void addIngredients() = 0;

    //制作饮品
    void makeDrink() {
        boilWater();
        brew();
        pourIntoCup();
        addIngredients();
    }
};

class MakeCoffee: public AbstractMakeDrink {

public:

    //冲泡咖啡
    void brew() {
        cout << "冲泡咖啡" << '\n';
    }

    //加入糖和牛奶
    void addIngredients() {
        cout << "加入糖和牛奶" << '\n';
    }
};

class MakeTea: public AbstractMakeDrink {

public:

    //冲泡茶叶
    void brew() {
        cout << "冲泡茶叶" << '\n';
    }

    //加入柠檬
    void addIngredients() {
        cout << "加入柠檬" << '\n';
    }
};

//制作函数
void doWork(AbstractMakeDrink* abs) {
    abs->makeDrink();
    delete abs; //释放
}

void test01() {

    //制作咖啡
    cout << "冲泡咖啡流程: " << '\n';
    doWork(new MakeCoffee);

    //制作茶
    cout << "\n冲泡茶叶流程: " << '\n';
    doWork(new MakeTea);
}

int main() {

    test01();

    system("pause");

    return 0;
}