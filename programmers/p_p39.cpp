#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int visited[101][101];
vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] != 'X' && visited[i][j] == 0) {
                queue<pair<int, int>> m;
                m.push({ i,j });                  //초기 위치 큐에 저장
                visited[i][j] = 1;               //초기 위치 방문처리 
                int sum = (maps[i][j] - '0');       //현재 위치 값 sum에 저장

                while (!m.empty()) {
                    int curx = m.front().first;     //젤 앞에 있는 값 호출 -> 현재 위치 
                    int cury = m.front().second;
                    m.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curx + dx[dir];                 //4방향 계산
                        int ny = cury + dy[dir];
                        if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;       //맵 범위 바깥일때 제외
                        if (maps[nx][ny] == 'X' || visited[nx][ny] == 1) continue;     //X표시된 곳이나 방문한 곳 제외
                        m.push({ nx,ny });                //현재위치 큐에 저장
                        visited[nx][ny] = 1;              //현재위치 방문처리
                        sum += (maps[nx][ny] - '0');
                    }
                }
                answer.push_back(sum);
            }

        }
    }
    if (answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}