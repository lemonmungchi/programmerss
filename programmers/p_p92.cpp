#include <string>
#include <vector>

using namespace std;
//4개의 블록을 파악 -> 제거 -> 밑으로 이동-> 다시 파악-> 반복
void fillEmpty(int m, int n, vector<string>& board) {  //빈공간을 내려주는 함수
    for (int j = 0; j < n; j++) {
        string tmp = "";
        for (int i = m - 1; i >= 0; i--) if (board[i][j] != ' ') tmp += board[i][j];     //채워져있는 칸이라면 tmp에 모두 추가
        int i = m - 1;          //젤 끝에서부터
        for (auto c : tmp) board[i--][j] = c;       //tmp에서 하나씩 꺼내서 젤밑에서부터 추가
        for (; i >= 0; i--) board[i][j] = ' ';         //나머지는 빈칸으로
    }

}

bool is_erase(int i, int j, vector<string>& board, vector<vector<bool>>& vis) {
    if (board[i][j] != board[i + 1][j] ||
        board[i][j] != board[i][j + 1] ||
        board[i][j] != board[i + 1][j + 1]) return false;
    vis[i][j] = true;
    vis[i + 1][j] = true;
    vis[i][j + 1] = true;
    vis[i + 1][j + 1] = true;
    return true;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> vis(m, vector<bool>(n, false)); //2차원 bool벡터 선언 및 초기화

    while (1) {
        bool done = true;
        fill(vis.begin(), vis.end(), vector<bool>(n, false)); //2차원 bool 벡터 초기화
        for (int i = 0; i < m - 1; i++) {         //비교를 위해 m-1,n-1까지
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] != ' ' && is_erase(i, j, board, vis)) done = false;
                //공백이 아니고 지울 수 있다면 방문체크 및 계속진행
            }
        }
        if (done) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) board[i][j] = ' '; //방문처리한=> 즉 지울 수 있는 칸은 지운다.
            }
        }
        fillEmpty(m, n, board); //빈공간 내리기
    }
    for (auto s : board) {
        for (auto c : s) if (c == ' ') answer++; //빈칸인 경우 지워진블록으로 추가
    }

    return answer;
}