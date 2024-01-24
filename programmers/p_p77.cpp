#include<vector>
#include<queue>
using namespace std;
int dx[4] = { 1,0,-1,0 };       //�ݽð���� �Ʒ�����
int dy[4] = { 0,1,0,-1 };
int width, height;
bool visited[101][101] = { 0 };
int bfs[101][101] = { 0 };

queue<pair<int, int>> q;
int solution(vector<vector<int> > maps)
{
    int answer = 0;

    width = maps[0].size();           //����
    height = maps.size();              //����

    q.push({ 0,0 });              //����
    visited[0][0] = 1;
    bfs[0][0] = 1;

    while (!q.empty()) {

        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx >= height || nx < 0 || ny >= width || ny < 0) continue;     //������ �̻�

            if (visited[nx][ny]) continue;           //�湮���� üũ

            if (maps[nx][ny] == 0) continue;              //������ üũ

            visited[nx][ny] = 1;
            q.push({ nx,ny });
            bfs[nx][ny] = bfs[curX][curY] + 1;
        }
    }

    if (!bfs[height - 1][width - 1]) answer = -1;
    else answer = bfs[height - 1][width - 1];

    return answer;
}