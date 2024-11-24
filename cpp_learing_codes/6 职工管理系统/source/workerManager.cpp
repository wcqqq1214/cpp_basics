#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


//构造函数
WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //1. 文件不存在
    if (!ifs.is_open()) {

        // cout << "文件不存在" << '\n';   //测试输出

        this->m_EmpNum = 0; //初始化人数

        this->m_FileIsEmpty = true; //初始化文件为空标志

        this->m_EmpArray = NULL;    //初始化数组指针

        ifs.close();
        return;
    }

    //2. 文件存在，但数据为空
    char ch;    //存储从文件中提取的字符
    ifs >> ch;  //读取文件的下一个字符存入ch
    //若读取成功，ch1 将包含文件中的下一个字符
    //若读取失败(如到达文件末尾)，ifs 流状态会被设置为 eof 状态
    if (ifs.eof()) {    //如果到达了文件末尾(EOF: end of file)，返回 true

        // cout << "文件为空" << '\n';  //测试输出

        this->m_EmpNum = 0;

        this->m_FileIsEmpty = true;

        this->m_EmpArray = NULL;

        ifs.close();
        return;
    }

    //3. 文件存在，并且记录有数据
    int num = this->get_EmpNum();
    // cout << "职工人数为: " << num << '\n';  //测试代码
    this->m_EmpNum = num;   //更新成员属性

    this->m_FileIsEmpty = false;

    //根据职工数创建数组
    this->m_EmpArray = new Worker*[this->m_EmpNum];

    //初始化数组 (将文件中的数据，存到数组中)
    this->init_Emp();

    //测试代码
    // for (int i = 0; i < m_EmpNum; i++) {

    //     cout << "职工号: " << this->m_EmpArray[i]->m_Id 
    //         << "\t职工姓名: " << this->m_EmpArray[i]->m_Name
    //         << "\t部门编号: " << this->m_EmpArray[i]->m_DeptId << '\n';
    // }

}

//展示菜单
void WorkerManager::Show_Menu() {

    cout << "***************************************" << '\n';
    cout << "********* 欢迎使用职工管理系统 ********" << '\n';
    cout << "*********** 0. 退出管理系统 ***********" << '\n';
    cout << "*********** 1. 增加职工信息 ***********" << '\n';
    cout << "*********** 2. 显示职工信息 ***********" << '\n';
    cout << "*********** 3. 删除离职职工 ***********" << '\n';
    cout << "*********** 4. 修改职工信息 ***********" << '\n';
    cout << "*********** 5. 查找职工信息 ***********" << '\n';
    cout << "*********** 6. 按照编号排序 ***********" << '\n';
    cout << "*********** 7. 清空所有文档 ***********" << '\n';
    cout << "***************************************" << '\n';
    cout << '\n';
}

//退出系统
void WorkerManager::ExitSystem() {

    cout << "欢迎下次使用" << '\n';
    system("pause");
    //return 只能结束当前函数，而不会影响程序的整体执行
    //在成员函数中退出整个程序，需要使用 exit(0)使用
    exit(0);     
}

//添加职工
void WorkerManager::Add_Emp() {

    bool idIsExist = false; //id是否存在的标志

    cout << "请输入增加职工数量: " << '\n';

    int addNum = 0; //保存用户的输入数量
    cin >> addNum;

    if (addNum > 0) {
        //计算新空间大小
        int newSize = this->m_EmpNum + addNum;

        //开辟新空间
        Worker** newSpace = new Worker*[newSize];

        //将原空间下的数据拷贝到新空间下
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //输入新数据
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;    //部门选择 

            cout << "请输入第" << i + 1 << "个新职工编号: " << '\n';
            cin >> id;

            //判断新职工的编号是否重复
            for (int j = 0; j < m_EmpNum; j++) {
                if (this->m_EmpArray[j]->m_Id == id) {
                    idIsExist = true;
                }
            }

            if (idIsExist) {
                cout << "编号重复，请重新输入" << '\n';

                //按任意键后  清屏回到上级目录
                system("pause");
                system("cls");

                return;
            }

            cout << "请输入第" << i + 1 << "个新职工姓名: " << '\n';
            cin >> name;

            cout << "请选择该职工的岗位: " << '\n';
            cout << "1. 普通职工" << '\n';
            cout << "2. 经理" << '\n';
            cout << "3. 老板" << '\n';
            cin >> dSelect;


            Worker* worker = NULL;
            switch (dSelect) {

                case 1: //普通职工
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //经理
                    worker = new Manager(id, name, 2);
                    break;
                case 3: //老板
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;
        }

        //释放原有空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        //更新新的职工人数
        this->m_EmpNum = newSize;

        //提示信息
        cout << "成功添加" << addNum << "名新职工!" << '\n';

        //更新职工不为空标志
        this->m_FileIsEmpty = false;

        //保存数据到文件中
        this->save();
    }
    else {
        cout << "输入有误" << '\n';
    }

    //按任意键后  清屏回到上级目录
    system("pause");
    system("cls");
}

//保存文件
void WorkerManager::save() {

    ofstream ofs;

    ofs.open(FILENAME, ios::out);   //用输出的方式打开文件  ————写文件

    //将每个人数据写入到文件中
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << '\n';
    }

    //关闭文件
    ofs.close();
    
}

//统计文件中的人数
int WorkerManager::get_EmpNum() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    //顺序提取：    ( >> 运算符以空白字符为分隔，读取的范围是从一个非空白字符到下一个空白字符之间的内容)
    //ifs >> id 读取文件中的员工编号，存储到 id 变量中。
    //ifs >> name 读取员工姓名，存储到 name 变量中。
    //ifs >> dId 读取部门编号，存储到 dId 变量中。
    //只要从文件中成功读取到这三个字段数据(即员工记录)，while 条件就为真，并进入循环体。

    while (ifs >> id && ifs >> name && ifs >> dId) {
        //记录人数
        num++;
    }

    ifs.close();

    return num;
}

//初始化职工数组
void WorkerManager::init_Emp() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    
    while (ifs >> id && ifs >> name && ifs >> dId) {

        Worker* worker = NULL;
    
        //根据不同部门的id创建不同对象
        if (dId == 1) { //1 普通员工

            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) {    //2 经理

            worker = new Manager(id, name, dId);
        }
        else {
        
            worker = new Boss(id, name, dId);
        }

        //存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }
 
    ifs.close();
}

//显示职工
void WorkerManager::Show_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空" << '\n';
    }
    else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();         
        }
    }

    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::Del_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空" << '\n';
    }
    else {

        //按照职工编号删除
        cout << "请输入想要删除职工的编号: " << '\n';
        int id;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1) {  //说明职工存在，并且删除掉index位置上的职工
        
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                //数据前移
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }

            this->m_EmpNum--;   //更新数组中记录人员个数

            //数据同步更新到文件中
            this->save();

            cout << "删除成功" << '\n';
        }
        else {
            cout << "删除失败，未找到该职工" << '\n';
        }

    }

    //按任意键后  清屏回到上级目录
    system("pause");
    system("cls");
}

//按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
int WorkerManager::IsExist(int id) {

    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;   
        }
    }

    return index;
}

//修改职工
void WorkerManager::Mod_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空" << '\n';
    }
    else {
        
        cout << "请输入修改职工的编号: " << '\n';
        int id;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1) {
            
            //查找到有编号的职工

            delete this->m_EmpArray[index];

            int newId;
            string newName;
            int dSelect;

            cout << "查到: " << id << "号职工，请输入新编号: " << '\n';
            cin >> newId;

            cout << "请输入新姓名: " << '\n';
            cin >> newName;

            cout << "请输入岗位: " << '\n';
            cout << "1. 普通职工" << '\n';
            cout << "2. 经理" << '\n';
            cout << "3. 老板" << '\n';
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect) {
                    
                case 1:
                    worker = new Employee(newId, newName, 1);
            
                case 2:
                    worker = new Manager(newId, newName, 2);
            
                case 3:
                    worker = new Boss(newId, newName, 3);

                default:
                    break;
            }

            //更改数据到数组中
            this->m_EmpArray[index] = worker;

            cout << "修改成功" << '\n';

            //保存到文件中
            this->save();
        }
        else {
            cout << "修改失败，未找到该职工" << '\n';
        }

    }

    //按任意键清屏
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::Find_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空" << '\n';
    }
    else {

        cout << "请输入查找方式: " << '\n';
        cout << "1. 按照职工编号寻找" << '\n';
        cout << "2. 按照姓名寻找" << '\n';
        
        int choice;
        cin >> choice;

        if (choice == 1) {  //1. 按照职工编号寻找

            cout << "请输入查找职工的编号: " << '\n';
            int id;
            cin >> id;

            int index = this->IsExist(id);

            if (index != -1) {
                
                cout << "查找成功，该职工的信息如下: " << '\n';
                this->m_EmpArray[index]->showInfo();
            }
            else {
                cout << "查找失败，未找到该职工" << '\n';
            }

        } 
        else if (choice == 2) { //2. 按照姓名寻找 (同名职工信息全部显示)

            cout << "请输入查找职工的姓名: " << '\n';
            string name;
            cin >> name;

            bool flag = false;  //查找到的标志

            for (int i = 0; i < this->m_EmpNum; i++) {

                if (this->m_EmpArray[i]->m_Name == name) {

                    cout << "查找成功，职工编号为: " << this->m_EmpArray[i]->m_Id
                        << "  信息如下: " << '\n';

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }

            if (flag == false) {
                cout << "查找失败，没有该职工的信息" << '\n';
            }

        }
        else {
            cout << "输入选项有误" << '\n';
        }

        //按任意键清屏
        system("pause");
        system("cls");   
    }
}

//排序职工 (按照职工编号排序)
void WorkerManager::Sort_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空" << '\n';
        system("pause");
        system("cls");
    }
    else {
        
        cout << "请选择排序方式: " << '\n';
        cout << "1. 按职工编号进行升序" << '\n';
        cout << "2. 按职工编号进行降序" << '\n';

        int choice;
        cin >> choice;

        //选择排序
        for (int i = 0; i < this->m_EmpNum; i++) {

            int minOrMax = i;   //声明 最小值 或 最大值 下标
            for (int j = i + 1; j < this->m_EmpNum; j++) {

                if (choice == 1) {  //升序

                    //认定 minOrMax 为 min
                    if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
                        minOrMax = j;
                    }
                }
                else {  //降序

                    //认定 minOrMax 为 max
                    if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
                        minOrMax = j;
                    } 
                }
            }

            if (i != minOrMax) {
                
                //1. 
                swap(this->m_EmpArray[i], this->m_EmpArray[minOrMax]);

                //2.
                // Worker* temp = this->m_EmpArray[i];
                // this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                // this->m_EmpArray[minOrMax] = temp;
            }
        }

        cout << "排序成功，排序后结果为: " << '\n';
        this->save();   //排序后的结果保存到文件中
        this->Show_Emp();   //Show_Emp()函数写有 按任意键清屏
    }
}

//清空文件
void WorkerManager::Clear_File() {

    cout << "确认清空?" << '\n';
    cout << "1. 确认" << '\n';
    cout << "2. 返回" << '\n';

    int choice;
    cin >> choice;

    if (choice == 1) {
        
        //打开模式 ios::trunc 如果存在 删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL) {
            
            //删除堆区的每个职工对象
            for (int i = 0; i < this->m_EmpNum; i++) {

                if (this->m_EmpArray[i] != NULL) {
                    delete this->m_EmpArray[i];
                }
            }

            //删除堆区数组指针
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;

            this->m_EmpNum = 0;

            this->m_FileIsEmpty = true;
        }

        cout << "清空成功" << '\n';
    }

    system("pause");
    system("cls");
}

//析构函数
WorkerManager::~WorkerManager() {

    if (this->m_EmpArray != NULL) {
        
        for (int i = 0; i < this->m_EmpNum; i++) {
            
            if (this->m_EmpArray[i] != NULL) {

                delete this->m_EmpArray[i];
            }
            
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
        }
    }   

}
