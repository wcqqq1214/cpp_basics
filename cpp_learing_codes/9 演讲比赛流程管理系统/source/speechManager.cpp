#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager() {

    initialize();
}

//展示菜单
void SpeechManager::show_Menu() {

    cout << '\n';
    cout << "**********************************" << '\n';
    cout << "******* 欢迎来参加演讲比赛 *******" << '\n';
    cout << "******** 1. 开始演讲比赛 *********" << '\n';
    cout << "******** 2. 查看往届记录 *********" << '\n';
    cout << "******** 3. 清空比赛记录 *********" << '\n';
    cout << "******** 0. 退出比赛程序 *********" << '\n';
    cout << "**********************************" << '\n';
    cout << '\n'; 
}

//退出系统
void SpeechManager::exitSystem() {

    cout << "欢迎下次使用" << '\n';
    system("pause");
    exit(0);
}

//初始化属性
void SpeechManager::initSpeech() {

    //容器保证为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->m_Index = 1;

    //初始化记录容器
    this->m_Record.clear();
}

//初始化创建12名选手
void SpeechManager::createSpeaker() {

    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {

        string name = "选手";
        name += nameSeed[i];

        //创建具体选手
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; j++) {
            sp.m_Score[j] = 0;
        }

        //创建12名选手编号, 并放到v1容器中
        this->v1.push_back(i + 10001);

        //选手编号 以及 对应的选手 存放到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

//开始比赛 - 比赛流程控制
void SpeechManager::startSpeech() {

    //第一轮比赛
    //1. 抽签
    this->drawLots();

    //2. 比赛
    this->speechContest();
    
    //3. 显示晋级结果
    this->showScore();

    //第二轮比赛
    this->m_Index++;
    //1. 抽签
    this->drawLots();

    //2. 比赛
    this->speechContest();

    //3. 显示最终结果
    this->showScore();

    //4.保存分数到文件中
    this->saveRecord();

    cout << "本届比赛结束!" << '\n';

    //重置比赛
    initialize();

    system("pause");
    system("cls");
}   

//抽签
void SpeechManager::drawLots() {

    cout << "第" << this->m_Index << "轮比赛选手正在抽签" << '\n';
    cout << "————————————————————————" << '\n';
    cout << "抽签后演讲顺序如下: " << '\n';

    if (this->m_Index == 1) {

        //第一轮比赛
        random_shuffle(v1.begin(), v1.end());
        for (auto it = v1.begin(); it != v1.end(); it++) {
            cout << *it << " ";
        }
        cout << '\n';
    }
    else {

        //第二轮比赛
        random_shuffle(v2.begin(), v2.end());
        for (auto it = v2.begin(); it != v2.end(); it++) {
            cout << *it << " ";
        }
        cout << '\n';
    }

    cout << "————————————————————————" << '\n';
    system("pause");
    cout << '\n';
}

//比赛
void SpeechManager::speechContest() {

    cout << "————————————— 第" << this->m_Index << "轮比赛开始 —————————————" << '\n';

    //由大到小排序
    //临时容器, 保存 key 分数, value 选手编号 (存放小组成绩)
    multimap<double, int, greater<double>> groupScore;

    int num = 0;    //记录人员数, 6个为一组

    vector<int> v_Src;  //比赛选手容器

    if (this->m_Index == 1) {

        v_Src = v1;
    }
    else {

        v_Src = v2;
    }  
    
    //遍历所有参赛选手
    for (auto it = v_Src.begin(); it != v_Src.end(); it++) {

        num++;

        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++) {

            double score = (rand() % 401 + 600) / 10.f;     //60.0 ~ 100.0
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());    //排序
        d.pop_front();      //去掉最高分
        d.pop_back();       //去掉最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f);      //获取总分
        double avg = sum / (double)d.size();                    //获取平均分

        //将平均分放入到map容器中
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        //6个人一组, 用临时容器保存
        groupScore.insert(make_pair(avg, *it));

        if (num % 6 == 0) {

            cout << "\n第" << num / 6 << "小组比赛名次: " << '\n';

            for (auto gsit = groupScore.begin(); gsit != groupScore.end(); gsit++) {

                cout << "id: " << gsit->second 
                    << " name: " << this->m_Speaker[gsit->second].m_Name
                    << " score: " << this->m_Speaker[gsit->second].m_Score[this->m_Index - 1] << '\n';    
            }  

            int count = 0;
            //取前三名
            for (auto gsit = groupScore.begin(); gsit != groupScore.end() && count < 3; gsit++, count++) {

                if (this->m_Index == 1) {

                    v2.push_back(gsit->second);
                }
                else {

                    vVictory.push_back(gsit->second);
                }
            }

            groupScore.clear();     //小组容器清空
        }   
    }
    cout << "\n————————————— 第" << this->m_Index << "轮比赛结束 —————————————" << '\n';
    system("pause");
}

//显示比赛结果 
void SpeechManager::showScore() {

    cout << "\n————————————— 第" << this->m_Index << "轮晋级选手信息如下 —————————————" << '\n';

    vector<int> v;

    if (this->m_Index == 1) {

        v = v2;
    }
    else {

        v = vVictory;
    }

    for (int i: v) {

        cout << "id: " << i 
            << " name: " << m_Speaker[i].m_Name
            << " score: " << m_Speaker[i].m_Score[this->m_Index - 1] << '\n'; 
    }
    cout << '\n';

    system("pause");
    system("cls");
    this->show_Menu();
}

//保存记录
void SpeechManager::saveRecord() {

    ofstream ofs;

    ofs.open("speech.csv", ios::out | ios::app);    //用追加的方式写文件

    //将每个人的数据写到文件中
    for (auto it = vVictory.begin(); it != vVictory.end(); it++) {

        ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << '\n';

    //关闭文件
    ofs.close();

    cout << "记录已经保存" << '\n';

    //有记录了, 文件不为空
    this->fileIsEmpty = false;
}

//读取记录
void SpeechManager::loadRecord() {

    ifstream ifs("speech.csv", ios::in);    //输入流对象 读取文件

    if (!ifs.is_open()) {

        // cout << "文件不存在" << '\n';
        this->fileIsEmpty = true;

        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {

        // cout << "文件为空" << '\n';
        this->fileIsEmpty = true;

        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch);    //把读取的最后一个字符放回流中, 以便下一次读取可以从该字符重新开始

    string data;
    int index = 1;
    // ifs >> data 读取第一个以空白字符(如空格、\t、\n)为分隔符的单词 (读取一行)
    while (ifs >> data) {

        vector<string> v;

        int pos = -1;   //查到','位置的变量
        int start = 0;

        while (true) {

            pos = data.find(",", start);    //从0开始查找 ',' (如果没有找到, 则返回 npos, 即 -1)
            if (pos == -1) {

                break;  //找不到, break返回
            }
            //参数1 起始位置    参数2 截取长度
            string tmp = data.substr(start, pos - start);   //找到了, 按照','的位置进行分割
            
            v.push_back(tmp);
            start = pos + 1;
        }

        this->m_Record.insert(make_pair(index, v)); //index代表第几届比赛
        index++;
    }

    ifs.close();
}

//显示往届记录
void SpeechManager::showRecord() {

    if (this->fileIsEmpty) {

        cout << "文件不存在, 或记录为空" << '\n';
    }
    else {

        for (auto it = m_Record.begin(); it != m_Record.end(); it++) {

            cout << "第" << it->first << "届 "
                << "冠军编号: " << it->second[0] << "  得分: " << it->second[1] << "   "
                << "亚军编号: " << it->second[2] << "  得分: " << it->second[3] << "   "
                << "季军编号: " << it->second[4] << "  得分: " << it->second[5] << '\n';
        }
    }

    system("pause");
    system("cls");
}

//清空记录
void SpeechManager::clearRecord() {

    cout << "确认清空?" << '\n';
    cout << "1. 确认" << '\n';
    cout << "2. 返回" << '\n';

    int select = 0;
    cin >> select;

    if (select == 1) {

        //打开模式  ios::trunc 如果存在, 删除文件并重新创建
        ofstream ofs("speech.csv", ios::trunc);

        ofs.close();

        //初始化
        initialize();

        cout << "清空成功!" << '\n';
    }
    
    system("pause");
    system("cls");
}

//析构函数
SpeechManager::~SpeechManager() {}

//private:

//初始化函数
void SpeechManager::initialize() {

    //初始化容器和属性
    this->initSpeech();

    //创建选手
    this->createSpeaker();

    //获取往届记录
    this->loadRecord();
}
