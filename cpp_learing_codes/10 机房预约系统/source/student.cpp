#include "student.h"


// 默认构造
Student::Student() {

}


// 有参构造 (学号, 姓名, 密码)
Student::Student(int id, string name, string pwd) {

    // 初始化属性
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {

        vCom.push_back(c);
    }

    ifs.close();
}


// 菜单界面
void Student::openMenu() {

    cout << "欢迎学生代表: " << this->m_Name << "登录!" << '\n';
    cout << "\t\t -----------------------------------------------\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                1. 申请预约                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                2. 查看我的预约               |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                3. 查看所有预约               |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                4. 取消预约                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                0. 注销登录                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t -----------------------------------------------\n";
    cout << "请选择你的操作: ";
}


// 申请预约
void Student::applyOrder() {

    cout << "机房开放时间为周一至周五!" << '\n';
    cout << "请输入申请预约的时间: " << '\n';
    cout << "1. 周一" << '\n';
    cout << "2. 周二" << '\n';
    cout << "3. 周三" << '\n';
    cout << "4. 周四" << '\n';
    cout << "5. 周五" << '\n';

    int date = 0;       // 日期
    int interval = 0;   // 时间段
    int room = 0;       // 机房编号

    while (true) {

        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "输入有误, 请重新输入" << '\n';
    }

    cout << "请输入申请预约的时间段: " << '\n';
    cout << "1. 上午" << '\n';
    cout << "2. 下午" << '\n';

    while (true) {

        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "输入有误, 请重新输入" << '\n';
    }

    cout << "请选择机房: " << '\n';
    for (int i = 0; i < vCom.size(); i++) {
        cout << vCom[i].m_ComId << "号机房容量: " << vCom[i].m_MaxNum << '\n';
    }

    while (true) {

        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "输入有误, 请重新输入" << '\n';
    }

    cout << "预约成功, 审核中!" << '\n';

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << '\n';      // 预约状态

    ofs.close();

    system("pause");
    system("cls");
}


// 查看我的预约
void Student::showMyOrder() {

    OrderFile of;   
    if (of.m_Size == 0) {

        cout << "无预约记录" << '\n';
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.m_Size; i++) {

        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {   // 找到自身预约
            
            cout << "预约日期: 周" << of.m_orderData[i]["date"];
            cout << "  时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << "  机房: " << of.m_orderData[i]["roomId"];
            string status = "  状态: ";     // 0 预约取消, 1 审核中, 2 预约成功, -1 预约失败
            if (of.m_orderData[i]["status"] == "1") {
                status += "审核中";
            }
            else if (of.m_orderData[i]["status"] == "2") {
                status += "预约成功";
            }
            else if (of.m_orderData[i]["status"] == "-1") {
                status += "预约失败, 审核未通过";
            }
            else if (of.m_orderData[i]["status"] == "0") {
                status += "预约已取消";
            }
            cout << status << '\n';
        }
    }

    system("pause");
    system("cls");
}


// 查看所有预约
void Student::showAllOrder() {

    OrderFile of;
    if (of.m_Size == 0) {

        cout << "无预约记录" << '\n';
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.m_Size; i++) {
        
        cout << i + 1 << ".  ";

        cout << "预约日期: 周" << of.m_orderData[i]["date"];
        cout << "  时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << "  学号: " << of.m_orderData[i]["stuId"];
        cout << "  姓名: " << of.m_orderData[i]["stuName"];
        cout << "  机房: " << of.m_orderData[i]["roomId"];
        string status = "  状态: ";     // 0 预约取消, 1 审核中, 2 预约成功, -1 预约失败
        if (of.m_orderData[i]["status"] == "1") {
            status += "审核中";
        }
        else if (of.m_orderData[i]["status"] == "2") {
            status += "预约成功";
        }
        else if (of.m_orderData[i]["status"] == "-1") {
            status += "预约失败, 审核未通过";
        }
        else if (of.m_orderData[i]["status"] == "0") {
            status += "预约已取消";
        }
        cout << status << '\n';
    }  

    system("pause");
    system("cls");
}


// 取消预约
void Student::cancelOrder() {

    OrderFile of;
    if (of.m_Size == 0) {

        cout << "无预约记录" << '\n';
        system("pause");
        system("cls");
        return;
    }

    cout << "审核中或预约成功的记录可以取消, 请输入想要取消的记录: " << '\n';

    vector<int> v;  // 把待删除的记录索引 保存到容器中
    int index = 1;
    for (int i = 0; i < of.m_Size; i++) {
        // 先判断是自身学号
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
            // 再筛选状态   审核中或预约成功
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {

                v.push_back(i);
                cout << index++ << ".  ";

            cout << "预约日期: 周" << of.m_orderData[i]["date"];
            cout << "  时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << "  机房: " << of.m_orderData[i]["roomId"];
            string status = "  状态: ";     // 0 预约取消, 1 审核中, 2 预约成功, -1 预约失败
            if (of.m_orderData[i]["status"] == "1") {
                status += "审核中";
            }
            else if (of.m_orderData[i]["status"] == "2") {
                status += "预约成功";
            }
            cout << status << '\n';
            }
        }
    }

    cout << "请输入取消的记录, 0代表返回" << '\n';
    int select = 0;
    while (true) {
    
        cin >> select;  
        if (select >= 0 && select <= v.size()) {

            if (select == 0) {
                break;
            }
            else {

                of.m_orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "已取消预约" << '\n';
                break;
            }
        }
        cout << "输入有误, 请重新输入" << '\n';
    }

    system("pause");
    system("cls");
}
