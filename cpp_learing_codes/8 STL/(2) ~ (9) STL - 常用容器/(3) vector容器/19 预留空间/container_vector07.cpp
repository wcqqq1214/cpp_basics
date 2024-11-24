#include <iostream>
using namespace std;
#include <vector>

//vector容器-预留空间 (减少vector在动态扩展容量时的扩展次数)

//函数原型:

//reserve(int len);     //容量预留len个元素长度, 预留位置不初始化, 元素不可访问


void test01() {

    vector<int> v;

    //利用reserve预留空间
    v.reserve(1e5);
    

    int num = 0;    //统计开辟内存次数
    int* p = NULL;
    for (int i = 0; i < 1e5; i++) {

        v.push_back(i);

        //每次开辟内存时(即创建新数组后), p失效, 需重新指向新数组的v[0]
        if (p != &v[0]) {

            p = &v[0];
            num++;
        }
    }

    cout << "num = " << num << '\n';
}


int main() {

    test01();

    system("pause");

    return 0;
}
