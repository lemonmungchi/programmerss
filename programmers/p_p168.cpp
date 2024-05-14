#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle;

    if (n == 1) {
        answer.push_back(1);
        return answer;
    }

    for (int i = 1; i <= n; i++) {              //트라이앵글 모양 잡아주기
        vector<int>tmp;
        for (int j = 0; j < i; j++) tmp.push_back(0);
        triangle.push_back(tmp);
    }

    int col = 0, row = 0;
    int num = 1;
    int turn = 0;                 //turn 한단계가 끝날수록 증가 -> 값이 들어갈 수 있는 곳 범위, 전체-turn 반복횟수
    while (true) {
        if (triangle[col][row] > 0) break;          //만약 채워져있는 칸이라면 끝

        for (int i = col; i < n - turn; i++) {            //아래로 이동 
            if (triangle[i][turn] == 0) {
                triangle[i][turn] = num++;
                col = i; row = turn;
            }
            else break;
        }
        row += 1; turn += 1;        //채워져있는 거 다음 부분부터 

        for (int j = row; j <= n - turn; j++) {            //오른쪽으로 이동 
            if (triangle[n - turn][j] == 0) {             //
                triangle[n - turn][j] = num++;
                col = n - turn; row = j;
            }
            else break;
        }
        col -= 1;         //채워져있는거 이전 부터

        for (int k = col; k >= turn; k--) {         //끝~채워진거 앞까지 위로
            if (triangle[k][k - turn + 1] == 0) {              //k~1번째 까지
                triangle[k][k - turn + 1] = num++;
                col = k; row = k - turn + 1;
            }
            else break;
        }
        col += 1;
    }

    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) answer.push_back(triangle[i][j]);
    }
    return answer;
}