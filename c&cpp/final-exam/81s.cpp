#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
class Speaker //选手类
{
  public:
    string name;  //选手姓名
    int score[3]; //选手每一轮比赛的得分
};

//产生选手
int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //参赛人员的名字
    random_shuffle(str.begin(), str.end());    //名字随机打乱
    for (int i = 0; i < 24; i++)
    {
        Speaker temp; //Speaker类对象
        temp.name = temp.name + str[i];
        mapSpeaker.insert(pair<int, Speaker>(100 + i, temp));
        //编写100+i，temp为Speaker对象
        //将编号与选手名字放入mapSpeaker容器中
    }
    for (int i = 0; i < 24; i++)
    {
        v.push_back(100 + i); //参加比赛的人员，其编号放入v容器中
    }
    return 0;
}

//选手抽签
int speech_contest_draw(vector<int> &v)
{
    random_shuffle(v.begin(), v.end()); //随机排序
    return 0;
}
//选手比赛
//参数：第几轮比赛  参数选手   将比赛得分修改在mapSpeaker中  比赛结果生成一个v2
int speech_contest(int index, vector<int> &v1,
                   map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
    //小组的比赛得分，记录下来，求出前三名与后三名
    multimap<int, int, greater<int>> multmapGroup; //存放小组成绩
                                                   //参数含义：得分，选手编号， 按从大到小排序
    int tempCount = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        tempCount++; //每参加一个选手，个数加1

        //评委打分
        deque<int> dscore;           //用来存储班委打的分
        for (int j = 0; j < 10; j++) //10个评委打分
        {
            int score = 50 + rand() % 50;
            dscore.push_back(score);
        }
        sort(dscore.begin(), dscore.end()); //将dscore容器中的分数排序
        dscore.pop_back();                  //去除最高分
        dscore.pop_front();                 //去除最低分

        //求平均分
        int scoresum = accumulate(dscore.begin(), dscore.end(), 0); //总分
        int scoreavg = scoresum / dscore.size();                    //平均分
        mapSpeaker[*it].score[index] = scoreavg;                    //将选手得分存入map容器中
                                                                    //得分与选手编号存入到了multmapGroup容器中
        multmapGroup.insert(pair<int, int>(scoreavg, *it));

        //处理分组
        if (tempCount % 6 == 0) //如果够6个选手了就分一组
        {
            cout << "小组成绩：" << endl;
            for (multimap<int, int, greater<int>>::iterator mit = multmapGroup.begin(); mit != multmapGroup.end(); mit++)
            {
                //输出顺序：编号  姓名  得分
                cout << mit->second << "\t"
                     << "选手"
                     << mapSpeaker[mit->second].name << "\t" << mit->first << endl;
            }

            //前3名晋级，晋级名单放到v2容器中
            while (multmapGroup.size() > 3) //multmapGroup容器是从大到小排序的
            {
                multimap<int, int, greater<int>>::iterator it = multmapGroup.begin();
                v2.push_back(it->second); //将选手编号存入到v2容器中
                multmapGroup.erase(it);   //删除it对应的元素，返回下一个元素的位置
            }
            multmapGroup.clear(); //完成之后将些容器清空，下一轮待用
        }
    }
    return 0;
}

//查看比赛结果
int speech_contest_print(int index, vector<int> &v,
                         map<int, Speaker> &mapSpeaker)
{
    printf("第%d轮晋级名单：\n", index + 1);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "编号：" << *it << "\t"
             << "选手" << mapSpeaker[*it].name << "\t" << mapSpeaker[*it].score[index] << endl;
    }
    return 0;
}

int main()
{
    //容器设计
    map<int, Speaker> mapSpeaker; //参加比赛的选手姓名、得分
    vector<int> v1;               //第1轮比赛的名单
    vector<int> v2;               //第2轮比赛的名单
    vector<int> v3;               //第3轮比赛的名单
    vector<int> v4;               //第4轮比赛的名单

    //设计流程
    //产生选手，得到第一轮选手的比赛名单
    GenSpeaker(mapSpeaker, v1);

    //第1轮  选手抽签  查看比赛结果
    cout << "按任意键开始第1轮比赛：" << endl;
    cin.get();
    speech_contest_draw(v1); //v1中存储的是第1轮选手的名单
    speech_contest(0, v1, mapSpeaker, v2);
    speech_contest_print(0, v2, mapSpeaker);

    //第2轮  选手抽签  查看比赛结果
    cout << "\n按任意键开始第2轮比赛：" << endl;
    cin.get();
    speech_contest_draw(v2);
    speech_contest(1, v2, mapSpeaker, v3);
    speech_contest_print(1, v3, mapSpeaker);

    //第3轮  选手抽签  查看比赛结果
    cout << "\n按任意键开始第3轮比赛：" << endl;
    cin.get();
    speech_contest_draw(v3);
    speech_contest(2, v3, mapSpeaker, v4);
    speech_contest_print(2, v4, mapSpeaker);
    system("pause");
    return 0;
}
