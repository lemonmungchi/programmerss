#include <string>
#include <vector>

using namespace std;
vector<int> v[200];
int DFS(int start, int now, int cnt) {         //DFS
    for (int i = 0; i < v[now].size(); i++) {
        if (v[now][i] != start) {               //�����ϳ��� �����
            cnt = DFS(now, v[now][i], cnt + 1);
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 2000;
    for (auto wire : wires) {
        v[wire[0]].push_back(wire[1]);
        v[wire[1]].push_back(wire[0]);
    }
    for (auto wire : wires) {
        int sum = DFS(wire[0], wire[1], 1);         //��� ����Ǿ� �ִ���
        int cmp = n - (sum * 2);                   
        answer = min(answer, abs(cmp));
    }
    return answer;
}