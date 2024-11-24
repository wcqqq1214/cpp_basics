#pragma once    //防止头文件重复包含
#include <iostream>     //包含输入输出流头文件
using namespace std;    //使用标准命名空间

#include <fstream>
#define FILENAME "empFile.txt"

#include "worker.h"

//1. 与用户的沟通菜单界面
//2. 对职工增删改查的操作
//3. 与文件的读写交互

class WorkerManager {

public:

    //构造函数
    WorkerManager();

    //展示菜单
    void Show_Menu();

    //退出系统
    void ExitSystem();

    //添加职工
    void Add_Emp();

    //保存文件
    void save();

    //统计文件中的人数
    int get_EmpNum();

    //初始化职工数组
    void init_Emp();

    //显示职工
    void Show_Emp();

    //删除职工
    void Del_Emp();

    //按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id);

    //修改职工
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //排序职工 (按照职工编号排序)
    void Sort_Emp();

    //清空文件
    void Clear_File();

    //析构函数
    ~WorkerManager();   


    int m_EmpNum;   //记录文件中的人数个数

    Worker** m_EmpArray;    //员工数组的指针

    bool m_FileIsEmpty; //标志文件是否为空
};