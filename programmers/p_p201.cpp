#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    set<pair<int, int>> points;          //교점 저장할 변수

    //교점계산
    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long a1 = line[i][0], b1 = line[i][1], c1 = line[i][2];
            long long a2 = line[j][0], b2 = line[j][1], c2 = line[j][2];
            long long inc = a1 * b2 - a2 * b1;              //행렬식
            if (inc == 0) continue;

            //교점계산
            long long x_num = b1 * c2 - b2 * c1;
            long long y_num = a2 * c1 - a1 * c2;

            //정수부분인지 계산
            if (x_num % inc == 0 && y_num % inc == 0) {
                int x = x_num / inc;
                int y = y_num / inc;
                points.insert({ x,y });
            }
        }
    }

    //격자판범위계산
    int min_x = INT_MAX, max_x = INT_MIN;
    int min_y = INT_MAX, max_y = INT_MIN;
    for (auto point : points) {
        min_x = min(min_x, point.first);
        max_x = max(max_x, point.first);
        min_y = min(min_y, point.second);
        max_y = max(max_y, point.second);
    }

    //격자판만들기
    int wid = max_x - min_x + 1;
    int height = max_y - min_y + 1;
    vector<string> grid(height, string(wid, '.'));            //.으로 격자판초기화
    for (auto point : points) {
        int x = point.first - min_x;            //x좌표 계산
        int y = max_y - point.second;           //y좌표 계산
        grid[y][x] = '*';
    }
    return grid;
}