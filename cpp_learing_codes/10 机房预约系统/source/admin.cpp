#include "admin.h"


// 打印学生信息 (全局函数)
void printStudent(const Student &s) {

    cout << "学号: " << s.m_Id << "\t姓名: " << s.m_Name << "\t密码: " << s.m_Pwd << '\n';    
}


// 打印老师信息 (全局函数)
void printTeacher(const Teacher &t) {

    cout << "职工号: " << t.m_empId << "\t姓名: " << t.m_Name << "\t密码: " << t.m_Pwd << '\n';
}


// 默认构造
Admin::Admin() {

}


// 有参构造 (管理员姓名, 密码)
Admin::Admin(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 初始化容器, 获取文件中的信息
    this->initVector();

    // 获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {

        vCom.push_back(c);
    }
    cout << "当前机房数量为: " << vCom.size() << '\n';

    ifs.close();
}


// 菜单界面
void Admin::openMenu()
{

    cout << "欢迎管理员: " << this->m_Name << "登录!" << '\n';
    cout << "\t\t -----------------------------------------------\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                1. 添加账号                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                2. 查看账号                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                3. 查看机房                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                4. 清空预约                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t|                0. 注销登录                   |\n";
    cout << "\t\t|                                              |\n";
    cout << "\t\t -----------------------------------------------\n";
    cout << "请选择你的操作: ";
}


// 添加账号
void Admin::addPerson() {

    cout << "请输入添加账号的类型: " << '\n';
    cout << "1. 添加学生" << '\n';
    cout << "2. 添加老师" << '\n';

    string fileName;    
    string tip;         // 提示 id
    string errorTip;    // 重复错误提示

    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1) {

        fileName = STUDENT_FILE;
        tip = "请输入学号: ";
        errorTip = "学号重复, 请重新输入";
    }
    else {

        fileName = TEACHER_FILE;
        tip = "请输入职工编号: ";
        errorTip = "职工号重复, 请重新输入";
    }

    // 利用 追加的方式 写文件
    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << tip << '\n';

    // 检测重复
    while (true) {

        cin >> id;

        bool ret = this->checkRepeat(id, select);

        if (ret) { // 有重复    
            cout << errorTip << '\n';
        }
        else {
            break;
        }
    }

    cout << "请输入姓名: " << '\n';
    cin >> name;

    cout << "请输入密码: " << '\n';
    cin >> pwd;
    
    // 向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << '\n';
    cout << "添加成功" << '\n';

    system("pause");
    system("cls");

    ofs.close();

    // 将刚添加的账号信息 更新到容器中
    this->initVector();
}


// 查看账号
void Admin::showPerson() {

    cout << "请选择查看内容: " << '\n';
    cout << "1. 查看所有学生" << '\n';
    cout << "2. 查看所有老师" << '\n';

    int select = 0;
    cin >> select;

    if (select == 1) {

        cout << "所有学生信息如下: " << '\n';
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else {

        cout << "所有老师信息如下: " << '\n';
        for_each(vTea.begin(), vTea.end(), printTeacher); 
    }
    system("pause");
    system("cls");
}


// 查看机房信息
void Admin::showComputer() {

    cout << "机房信息如下: " << '\n';
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
        
        cout << "机房编号: " << it->m_ComId << "\t机房最大容量: " << it->m_MaxNum << '\n';
    }
    system("pause");
    system("cls");
}


// 清空预约记录
void Admin::clearFile() {

    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功!" << '\n';
    system("pause");
    system("cls");
}


// 检测重复     
bool Admin::checkRepeat(int id, int type) {    
    // 参数: (传入id, 传入类型) 返回值: (true 代表有重复, false代表没有重复)

    if (type == 1) {

        // 检测学生
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {

            if (id == it->m_Id) {
                return true;
            }
        }
    }
    else {

        // 检测老师
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {

            if (id == it->m_empId) {
                return true;
            }
        }
    }
    return false;
}


// 初始化容器
void Admin::initVector() {

    // 确保容器是清空状态
    vStu.clear();
    vTea.clear();

    // 读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {

        cout << "文件读取失败" << '\n';
        return;
    }

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {

        vStu.push_back(s);
    }
    cout << "当前学生数量为: " << vStu.size() << '\n';
    ifs.close();


    // 读取老师文件信息
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {

        cout << "文件读取失败" << '\n';
        return;
    }

    Teacher t;
    while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd) {

        vTea.push_back(t);
    }
    cout << "当前老师数量为: " << vTea.size() << '\n';
    ifs.close();    
}
