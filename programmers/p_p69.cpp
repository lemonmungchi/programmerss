#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq1;            //�켱���� ť-> ������������ ���ĉ�.
queue<pair<int, int>> q1;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        q1.push({ i,priorities[i] });             //��ġ�� �ش簪 ����
        pq1.push(priorities[i]);                //�켱���� ����
    }
    int cnt = 1;
    while (1) {
        pair<int, int> qfront = q1.front();           //������ ���� ��ġ�� �ش簪 ����
        q1.pop();
        if (qfront.second == pq1.top()) {               //���� �ش簪�� �켱������ �ִٸ�
            if (qfront.first == location) {             //�ش簪�� �ش���ġ�� �ִٸ�
                answer = cnt;
                break;
            }
            else {
                pq1.pop();                          //�켱�������� ���ְ� �ش���ġ +1
                cnt++;
            }
        }
        else {
            q1.push({ qfront.first,qfront.second });      //�켱������ �ƴ϶�� �ڿ� �־��ֱ�
        }
    }
    return answer;
}