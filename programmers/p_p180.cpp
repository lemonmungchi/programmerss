#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // ��, ��, �Ʒ�, ��
int dy[4] = { 0, 0, 1, -1 };

bool check_dist(int i, int j, vector<string> place) {           //BFS
    bool visited[5][5] = { false };
    queue<pair<pair<int, int>, int>> q;
    visited[i][j] = true;
    q.push({ {i, j}, 0 });

    while (!q.empty()) {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for (int h = 0; h < 4; h++) {
            int nx = cur_x + dx[h];
            int ny = cur_y + dy[h];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

            if (visited[nx][ny] || place[nx][ny] == 'X') continue;        //��Ƽ���� �ִ� ��� �ʸӴ� Ž���� �ʿ� ����  

            if (place[nx][ny] == 'P' && dist + 1 <= 2) {            //����� �ִµ� ����ư�Ÿ��� �������� ������
                return false;
            }

            visited[nx][ny] = true;
            q.push({ {nx, ny}, dist + 1 });
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto place : places) {
        bool check = true;

        for (int i = 0; i < 5 && check; i++) {
            for (int j = 0; j < 5; j++) {
                if (place[i][j] == 'P') {
                    if (!check_dist(i, j, place)) {
                        check = false;
                        break;
                    }
                }
            }
        }

        answer.push_back(check ? 1 : 0);
    }

    return answer;
}
