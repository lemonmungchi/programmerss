#include <string>
using namespace std;
int dx[4] = { 1,0,-1,0 }; //반시계 방향 아래 오른 위 왼
int dy[4] = { 0,1,0,-1 }; //반시계 방향 아래 오른 위 왼
bool visited[11][11][4];            //방향까지 체크
int solution(string dirs) {
    int answer = 0;
    int startx = 5;               // 맵을 10,10에서 시작하는 것으로 변경 => 처리하기 편함 
    int starty = 5;

    for (int i = 0; i < dirs.length(); i++) {
        int nx;
        int ny;
        int dir;
        if (dirs[i] == 'D') {
            dir = 0;
            nx = startx + dx[0];
            ny = starty + dy[0];
        }
        else if (dirs[i] == 'R') {
            dir = 1;
            nx = startx + dx[1];
            ny = starty + dy[1];
        }
        else if (dirs[i] == 'U') {
            dir = 2;
            nx = startx + dx[2];
            ny = starty + dy[2];
        }
        else {
            dir = 3;
            nx = startx + dx[3];
            ny = starty + dy[3];
        }

        if (nx < 0 || nx>10 || ny < 0 || ny>10) continue;
        int countdir = (dir + 2) % 4;               //방향 전환 반대로 
        if (!visited[startx][starty][dir] && !visited[nx][ny][countdir]) {          //반대 방향 둘다 체크했을 때 안갔으면 방문처리
            answer++;
            visited[startx][starty][dir] = true;
        }

        startx = nx;
        starty = ny;
    }
    return answer;
}