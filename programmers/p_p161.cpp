#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int num = 1;
    int startX = 0; int endX = n - 1;
    int startY = 0; int endY = n - 1;
    while (num <= n * n) {
        for (int i = startY; i <= endY; ++i) {  //오른쪽으로 이동
            answer[startX][i] = num++;
        }
        startX++;
        for (int i = startX; i <= endX; ++i) {      //아래쪽
            answer[i][endY] = num++;
        }
        endY--;
        for (int i = endY; i >= startY; --i) {       //왼쪽
            answer[endX][i] = num++;
        }
        endX--;
        for (int i = endX; i >= startX; --i) {      //위쪽
            answer[i][startY] = num++;
        }
        startY++;
    }
    return answer;
}