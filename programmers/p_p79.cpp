#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[10001] = { 0 };
bool isall = false;			//�װ��� �� ����ߴ� �� Ȯ���� ���� 
int ticketcnt = 0;			//�װ��� ����� Ƚ��
vector<string> answer;
void dfs(vector<vector<string>> tickets, string ap) { //�װ���, ���� ����
    answer.push_back(ap);

    if (ticketcnt == tickets.size()) isall = true;          //�װ����� �� ����ߴٸ�
    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i]) continue;                   //�湮�Ѱ��̸� continue;
        if (tickets[i][0] == ap) {                  //�湮���������� �߿�
            visited[i] = true;                      //�湮ó��
            ticketcnt++;                            //�װ��ǻ��� ����
            dfs(tickets, tickets[i][1]);
            if (!isall) {                               //�װ��� �� ��������ʾҴٸ�
                answer.pop_back();                      //��Ʈ��ŷ
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN");                //������ ������ ICN
    return answer;
}