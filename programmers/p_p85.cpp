#include <string>
using namespace std;
int dx[4] = { 1,0,-1,0 }; //�ݽð� ���� �Ʒ� ���� �� ��
int dy[4] = { 0,1,0,-1 }; //�ݽð� ���� �Ʒ� ���� �� ��
bool visited[11][11][4];            //������� üũ
int solution(string dirs) {
    int answer = 0;
    int startx = 5;               // ���� 10,10���� �����ϴ� ������ ���� => ó���ϱ� ���� 
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
        int countdir = (dir + 2) % 4;               //���� ��ȯ �ݴ�� 
        if (!visited[startx][starty][dir] && !visited[nx][ny][countdir]) {          //�ݴ� ���� �Ѵ� üũ���� �� �Ȱ����� �湮ó��
            answer++;
            visited[startx][starty][dir] = true;
        }

        startx = nx;
        starty = ny;
    }
    return answer;
}