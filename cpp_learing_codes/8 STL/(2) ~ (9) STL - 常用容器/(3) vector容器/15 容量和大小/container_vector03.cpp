#include <iostream>
using namespace std;
#include <vector>

//vector容器-容量和大小


//函数原型:

//empty();              //判断容器是否为空

//capacity();           //容器的容量

//size();               //返回容器中元素的个数

//resize(int num);          //重新指定容器的长度为num, 若容器变长, 则以默认值0填充新位置, 
                            //如果容器变短, 则末尾超出容器长度的元素被删除

//resize(int num, elem);    //重新指定容器的长度为num, 若容器变长, 则以elem值填充新位置, 
                            //如果容器变短, 则末尾超出容器长度的元素被删除


void printVector(vector<int> &vec) {

    for (auto it = vec.begin(); it != vec.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        
        v1.push_back(i);
    }    
    
    printVector(v1);
    

    if (v1.empty()) {   //为真  代表容器为空
        
        cout << "v1为空" << '\n'; 
    }
    else {

        cout << "v1不为空" << '\n';
        cout << "v1的容量为: " << v1.capacity() << '\n';
        cout << "v1的大小为: " << v1.size() << '\n';
    }

    //重新指定大小
    v1.resize(15);      //利用重载版本, 可以指定默认填充值
    printVector(v1);    //如果重新指定的比原来长, 用默认值0填充新的位置

    v1.resize(5);
    printVector(v1);    //如果重新指定的比原来短了, 超出部分会删除掉
}


int main() {

    test01();

    system("pause");

    return 0;
}
