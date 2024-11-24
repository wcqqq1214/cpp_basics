#include <iostream>
using namespace std;
#include <fstream>
#include <string>

#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"


//  g++ *.cpp -o reservationSystem.exe
//  .\exe\reservationSystem.exe     (.\reservationSystem.exe)


// 进入管理员菜单界面
void adminMenu(Identity* &admin) {

    while (true) {

        // 调用子菜单
        admin->openMenu();

        // 将 父类指针 转为 子类指针, 调用子类中特有的接口
        Admin* ad = (Admin*) admin;
        int select = 0;

        cin >> select;

        if (select == 1) {  // 添加账号

            // cout << "添加账号" << '\n';
            ad->addPerson();
        }
        else if (select == 2) { // 查看账号

            // cout << "查看账号" << '\n';
            ad->showPerson();
        }
        else if (select == 3) { // 查看机房

            // cout << "查看机房" << '\n';
            ad->showComputer();
        }
        else if (select == 4) { // 清空预约

            // cout << "清空预约" << '\n';
            ad->clearFile();
        }
        else {  // 注销登录

            delete admin;   // 销毁掉堆区的对象
            cout << "注销成功" << '\n';
            system("pause");
            system("cls");
            return;
        }
    }
}


// 进入学生菜单界面
void studentMenu(Identity* &student) {

    while (true) {

        // 学生菜单
        student->openMenu();

        Student* stu = (Student*)student;

        int select = 0;
        cin >> select;

        if (select == 1) {  // 申请预约

            stu->applyOrder();
        }
        else if (select == 2) { // 查看自身预约

            stu->showMyOrder();
        }
        else if (select == 3) { // 查看所有预约

            stu->showAllOrder();
        }
        else if (select == 4) { // 取消预约

            stu->cancelOrder();
        }
        else {  // 注销登录

            delete student;
            cout << "注销成功" << '\n';
            system("pause");
            system("cls");
            return;
        }
    }
}


// 进入老师菜单界面
void teacherMenu(Identity* &teacher) {

    while (true) {

        // 老师菜单
        teacher->openMenu();

        Teacher* tea = (Teacher*)teacher;

        int select = 0;
        cin >> select;

        if (select == 1) {  // 查看所有预约

            tea->showAllOrder();
        }
        else if (select == 2) { // 审核预约

            tea->validOrder();
        }
        else {  // 注销登录

            delete teacher;
            cout << "注销成功" << '\n';
            system("pause");
            system("cls");
            return;
        }
    }
}


// 登录功能
void LoginIn(string fileName, int type) { 
    // type 登录的身份 (1 学生, 2 老师, 3 管理员)

    // 父类指针, 用于指向子类对象
    Identity* person = NULL;

    // 读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    // 判断文件是否存在
    if (!ifs.is_open()) {

        cout << "文件不存在" << '\n';
        ifs.close();
        return;
    }

    // 准备接收用户信息
    int id = 0;
    string name;
    string pwd; 

    if (type == 1) {    // 学生登录

        cout << "请输入你的学号: " << '\n';
        cin >> id;
    }
    else if (type == 2) {   // 老师登录

        cout << "请输入你的职工号: " << '\n';
        cin >> id;
    }

    cout << "请输入用户名: " << '\n';
    cin >> name;

    cout << "请输入密码: " << '\n';
    cin >> pwd;

    if (type == 1) {
        // 学生登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

            // 与用户输入的信息作对比
            if (id == fId && name == fName && pwd == fPwd) {

                cout << "学生验证登录成功!" << '\n';
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);

                // 进入学生身份的子菜单
                studentMenu(person);

                return;
            }
        }
    }
    else if (type == 2) {
        // 老师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

            if (id == fId && name == fName && pwd == fPwd) {

                cout << "老师验证登录成功!" << '\n';
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);

                // 进入老师身份的子菜单
                teacherMenu(person);

                return;
            }
        }
    }
    else if (type == 3) {
        // 管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {

            if (name == fName && pwd == fPwd) {

                cout << "管理员验证登录成功!" << '\n';
                system("pause");
                system("cls");
                person = new Admin(name, pwd);

                // 进入管理员身份的子菜单
                adminMenu(person);

                return;
            }
        }   
    }
    cout << "验证登录失败!" << '\n';

    system("pause");
    system("cls");
    return;
}

int main() {

    int select = 0;

    while (true) {

        cout << "========================= 欢迎来到机房预约系统 =========================" << '\n';
        cout << '\n' << "请输入你的身份: " << '\n';
        cout << "\t\t -----------------------------------------------\n";
        cout << "\t\t|                                              |\n";
        cout << "\t\t|                1. 学生代表                   |\n";
        cout << "\t\t|                                              |\n";
        cout << "\t\t|                2. 老    师                   |\n";
        cout << "\t\t|                                              |\n";
        cout << "\t\t|                3. 管 理 员                   |\n";
        cout << "\t\t|                                              |\n";
        cout << "\t\t|                0. 退出                       |\n";
        cout << "\t\t|                                              |\n";
        cout << "\t\t -----------------------------------------------\n";
        cout << "输入你的选择: ";

        cin >> select;  // 接受用户选择
    
        switch (select) {   // 根据用户的选择  实现不同的接口

            case 1: // 学生身份
                LoginIn(STUDENT_FILE, 1);
                break;

            case 2: // 老师身份
                LoginIn(TEACHER_FILE, 2);
                break;

            case 3: // 管理员身份
                LoginIn(ADMIN_FILE, 3);
                break;

            case 0: // 退出系统
                cout << "欢迎下次使用" << '\n';
                system("pause");
                return 0;
                break;

            default:
                cout << "输入有误, 请重新选择!" << '\n';
                system("pause");
                system("cls");
                break;
        }
    }

    system("pause");

    return 0;
}