#include <string>
#include <vector>

using namespace std;

int dh[4] = { 0,1,-1,0 };
int dw[4] = { 1,0,0,-1 };
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int size = board.size();
    int wsize = board[1].size();
    for (int i = 0; i < 4; i++) {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        if (h_check >= 0 && h_check < size && w_check >= 0 && w_check < wsize) {
            if (board[h][w] == board[h_check][w_check]) {
                answer++;
            }
        }
    }
    return answer;
}