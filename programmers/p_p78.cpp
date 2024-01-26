#include <string>
#include <vector>

using namespace std;
bool visited[201] = { 0 };
void dfs(int n, vector<vector<int>> computers, int cur) {     //������Լ� ��� �湮ó�� => ����Լ���
    visited[cur] = true;
    //����Լ�
    for (int i = 0; i < n; i++) {               //����� �Լ� ã������ ��ü ��ȸ
        if (!visited[i] && computers[cur][i] == 1) {          //����ǰ� �湮x�϶�
            dfs(n, computers, i);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //����� ��Ʈ��ũ�� Ȯ���ؾ���. => dfs �� 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, computers, i);
            answer++;
        }
    }
    return answer;
}