#include <iostream>
using namespace std;

//多态-案例3-电脑组装具体实现


//抽象不同零件类

//抽象的CPU类
class CPU {

public:
    //抽象的计算函数
    virtual void calculate() = 0;
};

//抽象的显卡类
class VideoCard {

public:
    //抽象的显示函数
    virtual void display() = 0;
};

//抽象的内存条类
class Memory {

public:
    //抽象的存储函数
    virtual void store() = 0;
};


//Intel
class Intel_CPU: public CPU {

public:
    void calculate() {
        cout << "Intel_CPU is calculating.." << '\n';
    }
};

class Intel_VideoCard: public VideoCard {
    
public:
    void display() {
        cout << "Intel_VideoCard is displaying.." << '\n';
    }
};

class Intel_Memory: public Memory {

public:
    void store() {
        cout << "Intel_Memory is storing.." << '\n';
    }
};

//Lenovo
class Lenovo_CPU: public CPU {

public:
    void calculate() {
        cout << "Lenovo_CPU is calculating.." << '\n';
    }
};

class Lenovo_VideoCard: public VideoCard {
    
public:
    void display() {
        cout << "Lenovo_VideoCard is displaying.." << '\n';
    }
};

class Lenovo_Memory: public Memory {

public:
    void store() {
        cout << "Lenovo_Memory is storing.." << '\n';
    }
};


//电脑类
class Computer {

private:

    CPU* m_cpu;     //CPU的零件指针
    VideoCard* m_videocard;     //显卡的零件指针
    Memory* m_memory;   //内存条的零件指针

public:

    Computer(CPU* cpu, VideoCard* videocard, Memory* memory) {
        m_cpu = cpu;
        m_videocard = videocard;
        m_memory = memory;
    }

    //提供工作的函数
    void doWork() {
        //让零件工作起来，调用接口
        m_cpu->calculate();
        m_videocard->display();
        m_memory->store();
    }

    ~Computer() {
        if (m_cpu != NULL) {
            delete m_cpu;
            m_cpu = NULL;  
        }

        if (m_videocard != NULL) {
            delete m_videocard;
            m_videocard = NULL;
        }

        if (m_memory != NULL) {
            delete m_memory;
            m_memory = NULL;
        }
    }
};


void test01() {

    cout << "Computer 1 is working" << '\n';
    Computer c1(new Intel_CPU, new Intel_VideoCard, new Intel_Memory);
    c1.doWork();

    cout << "\nComputer 2 is working" << '\n';
    Computer c2(new Intel_CPU, new Lenovo_VideoCard, new Intel_Memory);
    c2.doWork();

    cout << "\nComputer 3 is working" << '\n';
    Computer c3(new Lenovo_CPU, new Lenovo_VideoCard, new Lenovo_Memory);
    c3.doWork();
}

int main() {

    test01();

    system("pause");

    return 0;
}