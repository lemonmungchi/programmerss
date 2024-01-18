#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num;                //�湮�� ���� �� üũ�� ���� ����
bool visited[9];

int dfs(vector<vector<int>> dungeons, int k, int dcnt) {       //dcnt: ���� �湮�� ������
    num = max(num, dcnt);                           //���� dnt���� �ִ��� ���� ���� ������ 

    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] || dungeons[i][0] > k) continue;

        visited[i] = 1;                           //�湮ó��
        dfs(dungeons, k - dungeons[i][1], dcnt + 1);          //�湮�� ������ �Ƿε� �������� �Լ� ���ȣ��
        visited[i] = 0;                       //�� �ּ��� ���� ���ü��� �ִ� ����Ǽ� ���
    }

    return num;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    answer = dfs(dungeons, k, 0);
    return answer;
}