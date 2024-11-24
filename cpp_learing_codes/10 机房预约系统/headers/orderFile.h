#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include <string>
#include "globalFile.h"

class OrderFile {

public:

    // 构造函数
    OrderFile();

    // 更新预约记录
    void updateOrder();


    // 记录预约信息的容器   key --- 记录的条数  value --- 当前记录中所有信息
    map<int, map<string, string>> m_orderData;

    // 预约记录条数
    int m_Size;
};