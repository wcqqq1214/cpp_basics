#include <iostream>
using namespace std;

//函数的占位参数

//函数占位参数，占位参数也可以有默认参数 (例：int = 10)
void func(int a, int) {

    cout << "this is func" << '\n';
}

int main() {

    func(10, 10);   //占位参数必须填补

    system("pause");

    return 0;
}