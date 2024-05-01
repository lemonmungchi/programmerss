#include <string>
#include <vector>

using namespace std;

int dx[8] = { -1,1,0,0,-1,-1,1,1 };     //상하좌우 대각선
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };     //상하좌우 대각선
int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++) {            //순회하면서 
        for (int j = 0; j < board[0].size(); j++) {         //위,아래,좌,우,대각선에 지뢰가 있다면 위험지역
            if (board[i][j] == 1) {
                for (int k = 0; k < 8; k++) {
                    int curx = i + dx[k];
                    int cury = j + dy[k];
                    if (curx >= 0 && curx < board.size() && cury >= 0 && cury < board.size()) {
                        if (board[curx][cury] != 1) board[curx][cury] = 2;                   //안전지대가 아니라고 지뢰가 있는건 아니라서 1과는 다른값으로 할당
                    }
                }
            }
        }
    }

    for (int i = 0; i < board.size(); i++) {            //순회하면서 
        for (int j = 0; j < board[0].size(); j++) {         //위,아래,좌,우,대각선에 지뢰가 있다면 위험지역
            if (board[i][j] == 0) answer++;
        }
    }
    return answer;
}