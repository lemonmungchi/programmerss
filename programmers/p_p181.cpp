#include <string>
#include <vector>
#include <queue>
#define MAX 101
int w, h;
int dirX[4] = { -1,1,0,0 };
int dirY[4] = { 0,0,-1,1 };
using namespace std;
int BFS(int i, int j, vector<string> board) {
    queue<pair<pair<int, int>, int>> q;
    bool visited[MAX][MAX] = { 0, };
    int time = 1e9;

    q.push({ {i,j},0 });
    visited[i][j] = true;

    while (!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cur_time = q.front().second;
        q.pop();
        if (board[curx][cury] == 'G') time = min(time, cur_time);

        for (int i = 0; i < 4; i++) {
            int nx = curx + dirX[i];
            int ny = cury + dirY[i];

            if ((nx < 0 || nx >= w || ny < 0 || ny >= h) || board[nx][ny] == 'D') continue;           //못가는 곳은 넘어가기  

            while (true) {            //장애물 있는데까지 전진
                nx += dirX[i];
                ny += dirY[i];

                if ((nx < 0 || nx >= w || ny < 0 || ny >= h) || board[nx][ny] == 'D') {
                    nx -= dirX[i];
                    ny -= dirY[i];                //장애물까지 갔으니 그전 좌표 계산
                    break;
                }
            }
            if (visited[nx][ny]) continue;

            q.push({ {nx,ny},cur_time + 1 });
            visited[nx][ny] = true;
        }
    }

    return time == 1e9 ? -1 : time;
}

int solution(vector<string> board) {
    int answer = 0;
    w = board.size();
    h = board[0].size();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (board[i][j] == 'R') {
                answer = BFS(i, j, board);
            }
        }
    }
    return answer;
}