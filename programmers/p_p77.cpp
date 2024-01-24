#include<vector>
#include<queue>
using namespace std;
int dx[4] = { 1,0,-1,0 };       //반시계방향 아래부터
int dy[4] = { 0,1,0,-1 };
int width, height;
bool visited[101][101] = { 0 };
int bfs[101][101] = { 0 };

queue<pair<int, int>> q;
int solution(vector<vector<int> > maps)
{
    int answer = 0;

    width = maps[0].size();           //가로
    height = maps.size();              //세로

    q.push({ 0,0 });              //시작
    visited[0][0] = 1;
    bfs[0][0] = 1;

    while (!q.empty()) {

        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx >= height || nx < 0 || ny >= width || ny < 0) continue;     //사이즈 이상

            if (visited[nx][ny]) continue;           //방문여부 체크

            if (maps[nx][ny] == 0) continue;              //벽인지 체크

            visited[nx][ny] = 1;
            q.push({ nx,ny });
            bfs[nx][ny] = bfs[curX][curY] + 1;
        }
    }

    if (!bfs[height - 1][width - 1]) answer = -1;
    else answer = bfs[height - 1][width - 1];

    return answer;
}