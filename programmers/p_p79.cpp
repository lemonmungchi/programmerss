#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[10001] = { 0 };
bool isall = false;			//항공권 다 사용했는 지 확인할 변수 
int ticketcnt = 0;			//항공권 사용한 횟수
vector<string> answer;
void dfs(vector<vector<string>> tickets, string ap) { //항공권, 현재 공항
    answer.push_back(ap);

    if (ticketcnt == tickets.size()) isall = true;          //항공권을 다 사용했다면
    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i]) continue;                   //방문한곳이면 continue;
        if (tickets[i][0] == ap) {                  //방문하지않은곳 중에
            visited[i] = true;                      //방문처리
            ticketcnt++;                            //항공권사용수 증가
            dfs(tickets, tickets[i][1]);
            if (!isall) {                               //항공권 다 사용하지않았다면
                answer.pop_back();                      //백트레킹
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN");                //시작은 언제나 ICN
    return answer;
}