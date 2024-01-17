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
            progresses[i] += speeds[i];             //�۾��Ⱓ���ϱ�
            j++;
        }
        days.push_back(j);
    }
    q1.push(days[0]);
    for (int i = 1; i < days.size(); i++) {
        if (q1.front() >= days[i]) {
            q1.push(days[i]);                   //�۾��Ⱓ�� ª�ų� �������� ����
        }
        else {
            answer.push_back(q1.size());        //�۾��Ⱓ�� �� ����� �߰��Ѵٸ� ������ ���� �信 ���� �� �ʱ�ȭ
            while (!q1.empty()) q1.pop();
            q1.push(days[i]);                   //�� ������� �ʱ�ȭ
        }
    }
    if (!q1.empty()) answer.push_back(q1.size());           //������ �ϳ��� ���������� �־ ���� ��������ʴٸ� ���������̷� �߰�
    return answer;
}