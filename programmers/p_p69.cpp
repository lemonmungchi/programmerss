#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq1;            //우선순위 큐-> 내림차순으로 정렬됌.
queue<pair<int, int>> q1;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        q1.push({ i,priorities[i] });             //위치와 해당값 저장
        pq1.push(priorities[i]);                //우선순위 저장
    }
    int cnt = 1;
    while (1) {
        pair<int, int> qfront = q1.front();           //연산을 위해 위치와 해당값 추출
        q1.pop();
        if (qfront.second == pq1.top()) {               //만약 해당값이 우선순위에 있다면
            if (qfront.first == location) {             //해당값이 해당위치에 있다면
                answer = cnt;
                break;
            }
            else {
                pq1.pop();                          //우선순위에서 빼주고 해당위치 +1
                cnt++;
            }
        }
        else {
            q1.push({ qfront.first,qfront.second });      //우선순위가 아니라면 뒤에 넣어주기
        }
    }
    return answer;
}