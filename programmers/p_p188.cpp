#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int Timecalc(string  t) {
    return (60 * stoi(t.substr(0, 2))) + stoi(t.substr(3));
}
//�ð������� �ְ� ���� ��ġ�°� ó��
bool cmp(vector<string> a, vector<string> b) {
    return Timecalc(a[1]) < Timecalc(b[1]);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> pause_plan;

    sort(plans.begin(), plans.end(), cmp);        //�ð������� ����

    int curTime = Timecalc(plans[0][1]);
    int nextTime = Timecalc(plans[1][1]);
    int SumSub = 0;           //���ݱ��� ������ ������
    while (SumSub < plans.size() || !pause_plan.empty()) {
        //���� �����ص� ������ �ִٸ�
        if (!pause_plan.empty()) {
            //���� ������������ �������� �� �ߴٸ� ����� ���� ����
            if (SumSub == plans.size()) {
                answer.push_back(pause_plan.top().first);
                pause_plan.pop();
                continue;
            }
            //���� ������ �����ؾ��� �������� �ð��� �����ִٸ�
            if (curTime < nextTime) {
                int pauseTime = pause_plan.top().second;      //���� �����ؾ��ϴ� �ð�
                int availableTime = nextTime - curTime;        //���� ���డ�� �ð�

                if (pauseTime <= availableTime) {       //���� ���� �ð����� ��������� ���డ���ϴٸ�
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
        curTime = Timecalc(plans[SumSub][1]) + stoi(plans[SumSub][2]);      //��������
        nextTime = SumSub + 1 >= plans.size() ? 1440 : Timecalc(plans[SumSub + 1][1]);

        if (curTime > nextTime) {       //���� ���������ϴ� �߿� ���ο� ������ ���´ٸ�
            pause_plan.push({ plans[SumSub][0],curTime - nextTime });       //������ : ��������Ϸ���� �����ð�
            curTime = nextTime;
        }
        else {
            answer.push_back(plans[SumSub][0]);
        }

        SumSub++;
    }


    return answer;
}