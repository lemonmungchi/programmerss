#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int DIRS[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int n, m;
vector<vector<int>> land;
vector<vector<bool>> visited;
vector<vector<int>> component;      //같은 그룹묶어주기
unordered_map<int, int> component_size;     //그룹의 사이즈

//같은 그룹찾기 -> BFS로 
int bfs(int x, int y, int comp_id) {            //x,y,그룹아이디
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    component[x][y] = comp_id;
    int size = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        size++;

        for (int d = 0; d < 4; d++) {
            int nx = cx + DIRS[d][0];
            int ny = cy + DIRS[d][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && land[nx][ny] == 1) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                component[nx][ny] = comp_id;
            }
        }
    }

    return size;
}

int solution(vector<vector<int>> land_input) {
    land = land_input;
    n = land.size();
    m = land[0].size();
    visited.assign(n, vector<bool>(m, false));
    component.assign(n, vector<int>(m, -1));
    component_size.clear();

    int comp_id = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 석유가 있고 방문하지 않은 위치에서 BFS 실행
            if (land[i][j] == 1 && !visited[i][j]) {
                int size = bfs(i, j, comp_id);
                component_size[comp_id] = size;
                comp_id++;
            }
        }
    }

    vector<int> oil_per_column(m, 0);

    for (int j = 0; j < m; j++) {
        unordered_map<int, bool> touched;  // 현재 열에서 이미 포함된 덩어리를 추적하는 맵
        for (int i = 0; i < n; i++) {
            // 석유가 있고 현재 열에서 아직 포함되지 않은 덩어리라면 
            if (land[i][j] == 1 && !touched[component[i][j]]) {
                oil_per_column[j] += component_size[component[i][j]];  // 덩어리 크기를 현재 열의 석유량에 추가
                touched[component[i][j]] = true;  // 컴포넌트 아이디에 해다아하는 값이 없을때 -> 현재 덩어리를 포함했다고 표시
            }
        }
    }

    return *max_element(oil_per_column.begin(), oil_per_column.end());
}
