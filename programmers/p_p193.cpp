#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isValid(const vector<int>& positions, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // ���� ���� ���� �ִ���, �Ǵ� �밢���� ���� �ִ��� Ȯ��
        if (positions[i] == col || abs(positions[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& positions, int& answer) {
    if (row == n) {
        // ��� ���� ��ġ�� ���
        ++answer;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isValid(positions, row, col)) {
            positions[row] = col;
            solveNQueens(n, row + 1, positions, answer);
            positions[row] = -1; // ��Ʈ��ŷ
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> positions(n, -1); // �� ���� ���� ���� ��ġ
    solveNQueens(n, 0, positions, answer);
    return answer;
}