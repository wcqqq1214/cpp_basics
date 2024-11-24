#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ctime>
#include <fstream>
#include <string>
#include "speaker.h"

/*
创建管理类:
- 提供菜单界面与用户交互
- 对演讲比赛流程进行控制
- 与文件的读写交互
*/

class SpeechManager {

public:

    //构造函数
    SpeechManager();

    //展示菜单
    void show_Menu();

    //退出系统
    void exitSystem();

    //初始化容器和属性
    void initSpeech();

    //初始化创建12名选手
    void createSpeaker();

    //开始比赛 - 比赛流程控制
    void startSpeech();

    //抽签
    void drawLots();

    //比赛
    void speechContest();

    //显示比赛结果 
    void showScore();

    //保存记录到文件
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示往届记录
    void showRecord();

    //清空记录
    void clearRecord();

    //析构函数
    ~SpeechManager();

private:

    //初始化函数
    void initialize();

public:

    //比赛选手 容器 12人
    vector<int> v1;

    //第一轮晋级 容器 6人
    vector<int> v2;

    //胜利(前三名) 容器 3人
    vector<int> vVictory;

    //存放编号 以及 对应的具体选手 容器
    map<int, Speaker> m_Speaker;

    //记录比赛轮数
    int m_Index;

    //判断文件是否为空的标志
    bool fileIsEmpty;

    //往届记录
    map<int, vector<string>> m_Record;
};
