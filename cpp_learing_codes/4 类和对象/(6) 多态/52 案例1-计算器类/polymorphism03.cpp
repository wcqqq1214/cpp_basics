#include <iostream>
using namespace std;

//多态-案例1-计算器类

//多态的优点；
//1. 代码组织结构清晰
//2. 可读性强
//3. 利于前期和后期的扩展和维护


//普通实现
// class Calculator {

// public:

//     int m_Num1; //操作数1
//     int m_Num2; //操作数2

//     int getResult(string oper) {
//         if (oper == "+") {
//             return m_Num1 + m_Num2;
//         } 
//         else if (oper == "-") {
//             return m_Num1 - m_Num2;
//         } 
//         else if (oper == "*") {
//             return m_Num1 * m_Num2;
//         }
//         return -1; 
//     }

// };


//多态实现

//实现计算器抽象类
class AbstractCalculator {

public:

    int m_Num1;
    int m_Num2;

    virtual int getResult() {
        return 0;
    }
};

//加法计算器类
class AddCalculator: public AbstractCalculator {

public:

    int getResult() {
        return m_Num1 + m_Num2;
    }
};

//减法计算器类
class SubCalculator: public AbstractCalculator {

public:

    int getResult() {
        return m_Num1 - m_Num2;
    }
};

//乘法计算器类
class MulCalculator: public AbstractCalculator {

public:

    int getResult() {
        return m_Num1 * m_Num2;
    }
};

void test01() {
    
    //多态使用条件
    //父类指针或者引用指向子类对象

    //加法运算
    AbstractCalculator* abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;

    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << '\n';
    //用完记得销毁
    delete abc;

    //减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;

    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << '\n';
    delete abc;

    //乘法运算
    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;

    cout << abc->m_Num1 << " x " << abc->m_Num2 << " = " << abc->getResult() << '\n';
    delete abc;
}

int main() {

    test01();

    system("pause");

    return 0;
}