#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isValid(const vector<int>& positions, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // 같은 열에 퀸이 있는지, 또는 대각선에 퀸이 있는지 확인
        if (positions[i] == col || abs(positions[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& positions, int& answer) {
    if (row == n) {
        // 모든 퀸을 배치한 경우
        ++answer;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isValid(positions, row, col)) {
            positions[row] = col;
            solveNQueens(n, row + 1, positions, answer);
            positions[row] = -1; // 백트래킹
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> positions(n, -1); // 각 열에 대한 퀸의 위치
    solveNQueens(n, 0, positions, answer);
    return answer;
}