#include <iostream>
using namespace std;
#include <map>

//map容器-插入和删除


//函数原型:

//insert(elem);         //在容器中插入元素 

//clear();              //清除所有元素

//erase(pos);           //删除pos迭代器所指的元素, 返回下一个元素的迭代器
//erase(beg, end);      //删除区间[beg, end)的所有元素, 返回下一个元素的迭代器 
//erase(key);           //删除容器中值为key的元素


void printMap(const map<int, int> &m) {

    for (auto it = m.begin(); it != m.end(); it++) {

        cout << "key = " << it->first << " value = " << it->second << '\n';
    }
    cout << '\n';
}

void test01() {

    map<int, int> m;

    //插入
    //第一种方式
    m.insert(pair<int, int>(1, 10));

    //第二种方式
    m.insert(make_pair(2, 20));

    //第三种方式  (不建议使用)
    m.insert(map<int, int>::value_type(3, 30));

    //第四种方式   (不建议使用 [] 插入, 可以使用 [] 使key访问到value)
    m[4] = 40;

    //若访问一个不存在的键, 自动插入一个新元素, 默认值为0
    // cout << m[5] << '\n';   //m[5]不存在, 默认输出0, 并插入对组 (5, 0)

    printMap(m);

    //删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3); //按照key值删除
    printMap(m);

    // m.erase(m.begin(), m.end()); //清空
    m.clear();
    printMap(m);
}

int main() {

    test01();

    system("pause");

    return 0;
}