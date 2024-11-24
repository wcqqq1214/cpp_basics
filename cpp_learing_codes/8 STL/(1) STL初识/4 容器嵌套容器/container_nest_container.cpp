#include <iostream>
using namespace std;

//容器嵌套容器


#include <vector>

void test01() {

    vector< vector<int> > v;

    //创建小容器
    vector<int> v1; //1 2 3 4
    vector<int> v2; //2 3 4 5
    vector<int> v3; //3 4 5 6
    vector<int> v4; //4 5 6 7

    //向小容器中添加数据

    for (int i = 0; i < 4; i++) {
        
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    //将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //通过大容器, 把所有数据遍历一遍    (*it) 的类型可以通过 <> 里面的内容得知
    for (vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++) {

        //由上方 <> 得知, *it 代表 vector<int> 小容器
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {  

            cout << *vit << " ";
        }
        cout << '\n';
    }
}


int main() {

    test01();

    system("pause");

    return 0;
}