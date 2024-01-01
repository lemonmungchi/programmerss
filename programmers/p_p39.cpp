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
                m.push({ i,j });                  //�ʱ� ��ġ ť�� ����
                visited[i][j] = 1;               //�ʱ� ��ġ �湮ó�� 
                int sum = (maps[i][j] - '0');       //���� ��ġ �� sum�� ����

                while (!m.empty()) {
                    int curx = m.front().first;     //�� �տ� �ִ� �� ȣ�� -> ���� ��ġ 
                    int cury = m.front().second;
                    m.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curx + dx[dir];                 //4���� ���
                        int ny = cury + dy[dir];
                        if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;       //�� ���� �ٱ��϶� ����
                        if (maps[nx][ny] == 'X' || visited[nx][ny] == 1) continue;     //Xǥ�õ� ���̳� �湮�� �� ����
                        m.push({ nx,ny });                //������ġ ť�� ����
                        visited[nx][ny] = 1;              //������ġ �湮ó��
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