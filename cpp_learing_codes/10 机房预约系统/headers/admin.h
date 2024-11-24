#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "computerRoom.h"


// 打印学生信息 (全局函数)
void printStudent(const Student &s);


// 打印老师信息 (全局函数)
void printTeacher(const Teacher &t);


// 管理员类 
class Admin: public Identity {

public:

    // 默认构造
    Admin();

    // 有参构造 (管理员姓名, 密码)
    Admin(string name, string pwd);


    // 菜单界面
    virtual void openMenu();

    // 添加账号
    void addPerson();

    // 查看账号
    void showPerson();

    // 查看机房信息
    void showComputer();

    // 清空预约记录
    void clearFile();

    // 检测重复
    bool checkRepeat(int id, int type);


    // 初始化容器
    void initVector();

    // 学生容器
    vector<Student> vStu;

    // 老师容器
    vector<Teacher> vTea;

    // 机房容器
    vector<ComputerRoom> vCom;
};