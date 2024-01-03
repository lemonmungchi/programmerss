#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    int sum = 0; int len = 1000001;         //�ִ���̰�
    queue<pair<int, int>> q;             //�հ� ��ġ�� ������ ť-> ť�� ����

    for (int i = 0; i < sequence.size(); i++) {
        q.push({ sequence[i],i });
        sum += sequence[i];

        while (sum > k) {                   //���� �κ����� k���� ũ�ٸ� ���� �տ� ������ ����
            sum -= q.front().first;
            q.pop();
        }

        if (sum == k && q.size() < len) {                   //k�� ���� �κ����� ã������, �ʱ� ���̸� ���� 
            len = q.size();                           //���� �� ���̺��� �����鼭 �κ����� k�� �ش��ϴ� ���� ã�Ҵٸ� 
            answer[0] = q.front().second;             //answer ����
            answer[1] = q.back().second;
        }
    }
    return answer;
}