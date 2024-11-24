#pragma once
#include <iostream>
using namespace std;

//1. 可以对内置数据类型以及自定义数据类型的数据进行存储
//2. 将数组中的数据存储到堆区
//3. 构造函数中可以传入数组的容量
//4. 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//5. 提供尾插法和尾删法对数组中的数据进行增加和删除
//6. 可以通过下标的方式访问数组中的元素
//7. 可以获取数组中当前元素个数和数组的容量


//自己的通用数组类
template<class T>
class MyArray {

public:

    MyArray(int capacity);  //有参构造

    MyArray(const MyArray &arr); //拷贝构造函数

    MyArray& operator=(const MyArray &arr);  //重载 = 运算符  防止浅拷贝问题

    T& operator[](int index);   //重载 []   允许访问下标

    void Push_Back(const T &val); //尾插法增加元素

    void Pop_Back(); //尾删法删除元素

    int getCapacity();  //返回数组容量

    int getSize();  //返回数组大小  (当前元素的个数)
    
    ~MyArray();  //析构函数

private:

    T* pAddress;    //指针指向堆区开辟的真实数组

    int m_Capacity; //数组容量

    int m_Size;      //数组大小  (当前元素的个数)
};

template<class T>
MyArray<T>::MyArray(int capacity) { //有参构造

    this->m_Capacity = capacity;

    this->m_Size = 0;

    this->pAddress = new T[this->m_Capacity];
}

template<class T>
MyArray<T>::MyArray(const MyArray<T> &arr) { //拷贝构造函数

    this->m_Capacity = arr.m_Capacity;

    this->m_Size = arr.m_Size;

    //深拷贝
    this->pAddress = new T[arr.m_Capacity];

    //将arr中的数据拷贝过来
    for (int i = 0; i < this->m_Size; i++) {
        this->pAddress[i] = arr.pAddress[i];
    }
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T> &arr) {  //重载 = 运算符  防止浅拷贝问题

    //先判断原来堆区是否有数据，如果有，先释放
    if (this->pAddress != NULL) {

        delete[] this->pAddress;
        this->pAddress = NULL;

        this->m_Capacity = 0;
        this->m_Size = 0;
    }
        
    //深拷贝
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;

    this->pAddress = new T[arr.m_Capacity];
    
    for (int i = 0; i < this->m_Size; i++) {
        this->pAddress[i] = arr.pAddress[i];
    }
    
    return *this;
}

template<class T>
T& MyArray<T>::operator[](int index) {  //重载 [] 运算符  允许通过下标访问
    return this->pAddress[index];
}

template<class T>
void MyArray<T>::Push_Back(const T &val) { //尾插法增加元素

    //判断容量是否等于大小
    if (this->m_Capacity == this->m_Size) {
        
        cout << "容量已满" << '\n';
        return;
    }

    this->pAddress[this->m_Size] = val; //在数组末尾插入数据

    this->m_Size++; //更新数组大小
}

template<class T>
void MyArray<T>::Pop_Back() { //尾删法删除元素

    //让用户访问不到最后一个元素 (逻辑删除  )

    if (this->m_Size == 0) {

        cout << "没有元素可删除" << '\n';
        return;
    }

    this->m_Size--; //更新数组大小
}

template<class T>
int MyArray<T>::getCapacity() { //返回数组容量

    return this->m_Capacity;
}

template<class T>
int MyArray<T>::getSize() { //返回数组大小

    return this->m_Size;
}

template<class T>
MyArray<T>::~MyArray() {  //析构函数

    if (this->pAddress != NULL) {

        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}
