#include <iostream>
using namespace std;

int main() {

    int a = 10;

    int b;

    int* p = new int(a);
    b = *p;

    cout << b << endl;

    delete p;

    system("pause");

    return 0;
}