#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"

//   g++ *.cpp -o manage_system.exe

//   .\exe\manage_system.exe    (.\manage_system.exe)



int main() {

    //实例化管理者对象
    WorkerManager wm;

    int choice = 0; //用来存储用户的选项

    while (true) {

        //展示菜单
        wm.Show_Menu();
        cout << "请输入你的选择: " << '\n';
        cin >> choice;  //接收用户的选项

        switch (choice) {

        case 0: //退出系统
            wm.ExitSystem();
            break;
        case 1: //添加职工
            wm.Add_Emp();
            break;
        case 2: //显示职工
            wm.Show_Emp();
            break;
        case 3: //删除职工
            wm.Del_Emp();
            break;
        case 4: //修改职工
            wm.Mod_Emp();
            break;
        case 5: //查找职工
            wm.Find_Emp();
            break;
        case 6: //排序职工
            wm.Sort_Emp();
            break;
        case 7: //清空文档
            wm.Clear_File();
            break;
        default:
            system("cls");  //清屏
            break;
        }
 
    }

    system("pause");

    return 0;
}