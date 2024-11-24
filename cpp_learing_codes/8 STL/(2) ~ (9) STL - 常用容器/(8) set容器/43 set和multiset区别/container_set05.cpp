#include <iostream>
using namespace std;
#include <set>

//set容器-set和multiset区别


//区别:
//1. set不可以插入重复数据, 而multiset可以
//2. set插入数据的同时会返回插入结果, 表示插入是否成功 ( insert方法返回 pair<iterator, bool> )
//3. multiset不会检测数据, 因此可以插入重复数据 ( insert方法返回 iterator )


void test01() {

    set<int> s;

    pair<set<int>::iterator, bool> ret = s.insert(10);   

    if (ret.second) {   //如果第二个元素(bool)为true

        cout << "第一次插入成功" << '\n';
    }
    else {

        cout << "第一次插入失败" << '\n';
    }

    ret = s.insert(10);

    if (ret.second) {

        cout << "第二次插入成功" << '\n';
    }
    else {

        cout << "第二次插入失败" << '\n';
    }


    multiset<int> ms;

    //允许插入重复值
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';

}

int main() {

    test01();

    system("pause");

    return 0;
}