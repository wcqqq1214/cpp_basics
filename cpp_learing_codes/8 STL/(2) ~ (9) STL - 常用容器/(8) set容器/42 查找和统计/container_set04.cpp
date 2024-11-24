#include <iostream>
using namespace std;
#include <set>

//set容器-查找和统计


//函数原型:

//find(key);        //查找key是否存在, 若存在, 返回该元素的迭代器; 若不存在, 返回set.end()

//count(key);       //统计key的元素个数


void test01() {

    set<int> s1;

    //插入
    s1.insert(10);    
    s1.insert(30);    
    s1.insert(20);    
    s1.insert(40);    

    //查找
    auto pos = s1.find(50); 

    if (pos != s1.end()) {

        cout << "找到元素: " << *pos << '\n';
    }
    else {

        cout << "未找到元素" << '\n';
    }
}

void test02() {

    set<int> s1;

    //插入
    s1.insert(10);    
    s1.insert(30);    
    s1.insert(20);    
    s1.insert(40);

    //统计30的个数
    int num = s1.count(30);
    //对于set而言, 统计的结果只会是 0 或 1
    cout << "num = " << num << '\n';
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}