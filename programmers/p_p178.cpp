#include <string>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;

int w, h;
int dirX[4] = { -1, 1, 0, 0 };        //��,��,��,�Ʒ�
int dirY[4] = { 0, 0, -1, 1 };

int bfs(int stx, int sty, int dtx, int dty, vector<string> maps) {
    queue<pair<pair<int, int>, int>> q;                 //��ǥ �� �ð� ����      {{x,y},time}
    bool visited[MAX][MAX] = { 0, };
    int time = 1e9;

    q.push({ {stx,sty},0 });
    visited[stx][sty] = true;

    while (!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cur_time = q.front().second;
        q.pop();

        if (curx == dtx && cury == dty) time = min(time, cur_time);

        for (int i = 0; i < 4; i++) {
            int nx = curx + dirX[i];
            int ny = cury + dirY[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;           //������ ���� �Ѿ��  
            if (visited[nx][ny] || maps[nx][ny] == 'X')continue;

            q.push({ {nx,ny},cur_time + 1 });
            visited[nx][ny] = true;
        }
    }

    return time == 1e9 ? 0 : time;
}
int solution(vector<string> maps) {
    pair<int, int> start;
    pair<int, int> laber;
    pair<int, int> dest;

    w = maps.size();
    h = maps[0].size();

    int findcnt = 0;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (findcnt == 3) break;

            if (maps[i][j] == 'S') {
                start = { i,j };
                findcnt++;
            }
            else if (maps[i][j] == 'L') {
                laber = { i,j };
                findcnt++;
            }
            else if (maps[i][j] == 'E') {
                dest = { i,j };
                findcnt++;
            }
        }
    }

    int sttolb = bfs(start.first, start.second, laber.first, laber.second, maps);           //����� ~ ���ִ� ������ 
    int lbtodt = sttolb ? bfs(laber.first, laber.second, dest.first, dest.second, maps) : -1;           //�����~ ���ִ� ������ �� �� �ִٸ� ��~������������ ��� 

    return (lbtodt == -1 || lbtodt == 0) ? -1 : sttolb + lbtodt;
}