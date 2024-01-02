#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> visited(1000000, 0);                  //����� ���� ���� 0���� �ʱ�ȭ
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();                  //���� �տ���- ������ġ ��������
        q.pop();
        if (cur == y) return visited[cur];     //y�� �������� ���� �� ��������
        int dir[3] = { cur + n,cur * 2,cur * 3 };
        for (int i = 0; i < 3; i++) {
            int nx = dir[i];
            if (nx > y || visited[nx] != 0) continue;      //y���� ũ�ų� �̹� ����ѰŶ�� ��ŵ
            visited[nx] = visited[cur] + 1;
            q.push(nx);
        }
    }

    return -1;
}