#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "identity.h"
#include "orderFile.h"

// 老师类 
class Teacher: public Identity {

public:

    // 默认构造
    Teacher();

    // 有参构造 (职工编号, 姓名, 密码)
    Teacher(int empId, string name, string pwd);


    // 菜单界面
    virtual void openMenu();

    // 查看所有预约
    void showAllOrder();

    // 审核预约
    void validOrder();

    int m_empId;       // 教师编号
};