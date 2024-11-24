#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

//STL案例1-评委打分

//案例描述:
//有5名选手: 选手ABCDE, 10个评委分别对每一名选手打分, 去掉最高分, 去掉最低分, 取平均分

//实现步骤:

//1. 创建5名选手, 放到vector中

//2. 遍历vector容器, 取出来每一个选手, 执行for循环, 可以把10个评分打分存到deque容器中

//3. sort算法对deque容器中的分数排序, 去掉最高分和最低分

//4. deque容器遍历一遍, 累加总分

//5. 获取平均分


//选手类
class Person {

public:

    Person(string name, int score) {
        this->m_Name = name;
        this->m_Score = score;
    }

    void showPerson() {

        cout << "name = " << m_Name << " score = " << m_Score << '\n';
    }

    string m_Name;  //姓名
    int m_Score;    //平均分
};

void createPerson(vector<Person> &v) {
    
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++) {

        string name = "选手";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        //将创建的Person对象 放入到容器中
        v.push_back(p);
    }
}

void setScore(vector<Person> &v) {

    for (auto it = v.begin(); it != v.end(); it++) {

        //将评委的分数 放入deque容器中
        deque<int> d;
        for (int i = 0; i < 10; i++) {

            //rand() % 41 生成的值在 [0, 40] 的范围内 (对 N % M 来说，结果总是 0 到 M-1 之间的整数)
            int score = rand() % 41 + 60;   // 60 ~ 100 的随机分
            d.push_back(score);
        }

        // //打印评委的打分 (测试)
        // cout << it->m_Name << " 打分: " << '\n';
        // for (auto dit = d.begin(); dit != d.end(); dit++) {

        //     cout << *dit << " ";
        // }
        // cout << '\n';

        //排序
        sort(d.begin(), d.end());

        //去除最高和最低分
        d.pop_back();  
        d.pop_front();

        //取平均分
        int sum = 0;
        for (auto dit = d.begin(); dit != d.end(); dit++) {

            sum += *dit;    //累加每个评委的分数
        }

        int avg = sum / d.size();

        //将平均分赋值给选手
        it->m_Score = avg;
    }

}

void showScore(const vector<Person> &v) {

    for (auto it = v.begin(); it != v.end(); it++) {

        cout << "姓名: " << it->m_Name << " 得分: " << it->m_Score << '\n';
    }
}

int main() {

    //随机数种子
    srand((unsigned int)time(NULL));

    //1. 创建5名选手
    vector<Person> v;   //存放选手的容器
    createPerson(v);

    //2. 给5名选手打分
    setScore(v);

    //3. 显示最后得分
    showScore(v);

    system("pause");

    return 0;
}