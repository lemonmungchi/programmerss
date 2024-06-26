#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int Timecalc(string  t) {
    return (60 * stoi(t.substr(0, 2))) + stoi(t.substr(3));
}
//시간순으로 넣고 만약 겹치는거 처리
bool cmp(vector<string> a, vector<string> b) {
    return Timecalc(a[1]) < Timecalc(b[1]);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> pause_plan;

    sort(plans.begin(), plans.end(), cmp);        //시간순으로 정렬

    int curTime = Timecalc(plans[0][1]);
    int nextTime = Timecalc(plans[1][1]);
    int SumSub = 0;           //지금까지 수행한 과제합
    while (SumSub < plans.size() || !pause_plan.empty()) {
        //만약 정지해둔 과제가 있다면
        if (!pause_plan.empty()) {
            //만약 마지막순서의 과제까지 다 했다면 멈춰둔 과제 수행
            if (SumSub == plans.size()) {
                answer.push_back(pause_plan.top().first);
                pause_plan.pop();
                continue;
            }
            //만약 다음에 수행해야할 과제까지 시간이 남아있다면
            if (curTime < nextTime) {
                int pauseTime = pause_plan.top().second;      //과제 수행해야하는 시간
                int availableTime = nextTime - curTime;        //과제 수행가능 시간

                if (pauseTime <= availableTime) {       //만약 남은 시간동안 멈춘과제를 수행가능하다면
                    answer.push_back(pause_plan.top().first);
                    pause_plan.pop();
                    curTime += pauseTime;
                }
                else {
                    pause_plan.top().second = pauseTime - availableTime;
                    curTime = nextTime;
                }
                continue;
            }
        }
        curTime = Timecalc(plans[SumSub][1]) + stoi(plans[SumSub][2]);      //과제수행
        nextTime = SumSub + 1 >= plans.size() ? 1440 : Timecalc(plans[SumSub + 1][1]);

        if (curTime > nextTime) {       //만약 과제수행하는 중에 새로운 과제가 들어온다면
            pause_plan.push({ plans[SumSub][0],curTime - nextTime });       //과제명 : 과제수행완료까지 남은시간
            curTime = nextTime;
        }
        else {
            answer.push_back(plans[SumSub][0]);
        }

        SumSub++;
    }


    return answer;
}