#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    queue<int> q1;
    for (int i = 0; i < progresses.size(); i++) {
        int j = 0;
        while (progresses[i] < 100) {
            progresses[i] += speeds[i];             //작업기간구하기
            j++;
        }
        days.push_back(j);
    }
    q1.push(days[0]);
    for (int i = 1; i < days.size(); i++) {
        if (q1.front() >= days[i]) {
            q1.push(days[i]);                   //작업기간이 짧거나 같을때는 저장
        }
        else {
            answer.push_back(q1.size());        //작업기간이 더 긴것을 발견한다면 그전의 길이 답에 저장 및 초기화
            while (!q1.empty()) q1.pop();
            q1.push(days[i]);                   //더 긴것으로 초기화
        }
    }
    if (!q1.empty()) answer.push_back(q1.size());           //마지막 하나가 남았을때도 있어서 만약 비어있지않다면 마지막길이로 추가
    return answer;
}