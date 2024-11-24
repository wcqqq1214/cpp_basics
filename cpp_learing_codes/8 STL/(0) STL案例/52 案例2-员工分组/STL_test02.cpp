#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <ctime>

//案例描述
//公司今天招聘了10个员工(ABCDEFGHIJ), 10名员工进入公司之后, 需要指派员工在哪个部门工作
//员工信息有: 姓名 工资组成;  部门分为: 策划 美术 研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入, key(部门编号) value(员工)
//分部门显示员工信息


//实现步骤:
//1. 创建10名员工, 放到vector中
//2. 遍历vector容器, 取出每名员工, 进行随机分组
//3. 分组后, 将员工部门编号作为key, 具体员工作为value, 放入到multimap容器中
//4. 分部门显示员工信息


class Employee {

public:

    Employee(string name, int sal) {

        this->m_Name = name;
        this->m_Sal = sal;
    }

    string m_Name;      //姓名
    int m_Sal;          //工资
};

//1. 创建员工
void createEmployee(vector<Employee> &v) {

    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) {
        string name = "员工";
        name += nameSeed[i];

        //随机分配工资 6000 ~ 8000
        int sal = rand() % 2001 + 6000; 

        Employee e(name, sal);

        v.push_back(e);
    }
}

//2. 员工分组
void setGroup(const vector<Employee> &v, multimap<int, Employee> &mp) {

    for (auto it = v.begin(); it != v.end(); it++) {

        //随机分配部门 1 ~ 3 (1-策划 2-美术 3-研发)
        int deptId = rand() % 3 + 1;
        //key: 部门编号     value: 具体员工 
        mp.insert(make_pair(deptId, *it));
    } 
}

//3. 分组显示信息
void showInfo(const multimap<int, Employee> &mp) {

    cout << "策划部门: " << '\n';
    
    auto pos = mp.find(1);
    int count = mp.count(1);    //统计部门具体人数
    int index = 0;
    for (; pos != mp.end() && index < count; pos++, index++) {

        cout << "姓名: " << pos->second.m_Name
            << " 工资: " << pos->second.m_Sal << '\n';
    }

    cout << "\n美术部门: " << '\n';
    
    pos = mp.find(2);
    count = mp.count(2);    //统计部门具体人数
    index = 0;
    for (; pos != mp.end() && index < count; pos++, index++) {

        cout << "姓名: " << pos->second.m_Name
            << " 工资: " << pos->second.m_Sal << '\n';
    }

    cout << "\n研发部门: " << '\n';
    
    pos = mp.find(3);
    count = mp.count(3);    //统计部门具体人数
    index = 0;
    for (; pos != mp.end() && index < count; pos++, index++) {

        cout << "姓名: " << pos->second.m_Name
            << " 工资: " << pos->second.m_Sal << '\n';
    }
}

int main() {

    //随机数种子
    srand((unsigned int)time(NULL));

    //1. 创建员工
    vector<Employee> vEmployee; //存放员工的容器
    createEmployee(vEmployee);

    //2. 员工分组
    multimap<int, Employee> mEmployee;
    setGroup(vEmployee, mEmployee);

    //3. 分组显示信息
    showInfo(mEmployee);

    system("pause");

    return 0;
}