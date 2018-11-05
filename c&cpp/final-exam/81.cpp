#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 选手类
class Player
{
  public:
    string id;
    double score;
};

// 评委类
class Judge
{

  public:
    // 给选手打分
    double scoreForPlayer(Player p)
    {
        // todo：具体的打分逻辑...
    }
};

class Contest
{

    vector<Player> players;
    vector<Judge> judges;

  public:
    // 构造函数，初始化参赛选手和评委们
    Contest(vector<Player> p, vector<Judge> j) : players(p), judges(j)
    {
    }
    void startContest()
    {
        // 分组第一轮
        vector<Player> group1_1;
        vector<Player> group1_2;
        vector<Player> group1_3;
        vector<Player> group1_4;
        for (int i = 0; i < 24; i++)
        {
            if (i < 6)
            {
                group1_1.push_back(players[i]);
                continue;
            }
            else if (i < 12)
            {
                group1_2.push_back(players[i]);
                continue;
            }
            else if (i < 18)
            {
                group1_3.push_back(players[i]);
                continue;
            }
            else
            {
                group1_4.push_back(players[i]);
            }
        }
        // 开始分组比赛
        startGroupContest(group1_1);
        startGroupContest(group1_2);
        startGroupContest(group1_2);
        startGroupContest(group1_3);
    }
    // 开始小组比赛
    void startGroupContest(vector<Player> players)
    {
        // 对每位选手进行打分
        for (int i = 0; i < 6; i++)
        {
            // 从评委那获取评分
            players[i].score = getPlayerScore(players[i]);
        }

    }
    double getPlayerScore(Player player)
    {
        // 每位评委对该选手进行打分
        vector<double> scores;
        for (int i = 0; i < 10; i++)
        {
            scores.push_back(judges[i].scoreForPlayer(player));
        }
        // 排序
        sort(scores.begin(),scores.end());
        // 去掉最高分去掉最低分
        scores.erase(scores.begin());
        scores.erase(scores.end()--);
        //求平均分
        double count = 0;
        for(int i = 0 ; i < 8 ; i++){
            count += scores[i];
        }
        return count / 8;
    }
};

int main()
{
    return 0;
}