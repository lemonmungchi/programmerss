#include <string>
#include <vector>
#include <queue>

using namespace std;
//큰값 저장 및 검사
int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int answer = 0;
    for (int i = 0; i < enemy.size(); i++) {
        if (n >= enemy[i]) {        //만약 현재가진 병사로 막을 수 있다면
            n -= enemy[i];
            pq.push(enemy[i]);      //최대적 수 저장
        }
        else {
            if (k > 0) {            //무적권이 남아있다면
                if (!pq.empty() && pq.top() > enemy[i]) {  //만약 전에 최대였던 수가 현재적보다 크다면
                    n += pq.top();                              //무적권을 사용해서 돌려받기
                    pq.pop();
                    pq.push(enemy[i]);
                    n -= enemy[i];                 //전에 무적권을 쓰고 지금꺼는 병사로 막기
                }
                k--;
            }
            else
                return i;
        }
    }

    return enemy.size();
}