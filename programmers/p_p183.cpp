#include <string>
#include <vector>
#include <queue>

using namespace std;
//ū�� ���� �� �˻�
int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int answer = 0;
    for (int i = 0; i < enemy.size(); i++) {
        if (n >= enemy[i]) {        //���� ���簡�� ����� ���� �� �ִٸ�
            n -= enemy[i];
            pq.push(enemy[i]);      //�ִ��� �� ����
        }
        else {
            if (k > 0) {            //�������� �����ִٸ�
                if (!pq.empty() && pq.top() > enemy[i]) {  //���� ���� �ִ뿴�� ���� ���������� ũ�ٸ�
                    n += pq.top();                              //�������� ����ؼ� �����ޱ�
                    pq.pop();
                    pq.push(enemy[i]);
                    n -= enemy[i];                 //���� �������� ���� ���ݲ��� ����� ����
                }
                k--;
            }
            else
                return i;
        }
    }

    return enemy.size();
}