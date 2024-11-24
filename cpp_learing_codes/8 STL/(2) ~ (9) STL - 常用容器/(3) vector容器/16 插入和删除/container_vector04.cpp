#include <iostream>
using namespace std;
#include <vector>

//vector容器-插入和删除


//函数原型:

//push_back(elem);      //尾部插入元素elem

//pop_back();           //删除最后一个元素

//insert(const_iterator pos, elem);             //迭代器指向位置pos插入元素elem

//insert(const_iterator pos, int count, elem);  //迭代器指向位置pos插入count个元素elem

//erase(const_iterator pos);                        //删除迭代器指向的元素

//erase(const_iterator start, const_iterator end);  //删除迭代器从start到end之间的元素

//clear();              //删除容器中的所有元素


void printVector(vector<int> &vec) {

    for (auto it = vec.begin(); it != vec.end(); it++) {

        cout << *it << " ";
    }
    cout << '\n';
}

void test01() {

    vector<int> v1;

    //尾插法插入数据
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    //遍历
    printVector(v1);    //10 20 30 40 50


    //尾删
    v1.pop_back();

    printVector(v1);    //10 20 30 40

    
    //指定位置插入 (第一个参数是迭代器)
    v1.insert(v1.begin(), 100); 

    printVector(v1);    //100 10 20 30 40


    v1.insert(v1.begin(), 2, 1000); 

    printVector(v1);    //1000 1000 100 10 20 30 40


    //删除 (参数也是迭代器)
    v1.erase(v1.begin());   

    printVector(v1);    //1000 100 10 20 30 40


    // v1.erase(v1.begin(), v1.end()); //相当于清空
    v1.clear();

    printVector(v1);    // (空)
}


int main() {

    test01();

    system("pause");

    return 0;
}
