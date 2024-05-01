#include <string>
#include <vector>

using namespace std;

int dx[8] = { -1,1,0,0,-1,-1,1,1 };     //�����¿� �밢��
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };     //�����¿� �밢��
int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++) {            //��ȸ�ϸ鼭 
        for (int j = 0; j < board[0].size(); j++) {         //��,�Ʒ�,��,��,�밢���� ���ڰ� �ִٸ� ��������
            if (board[i][j] == 1) {
                for (int k = 0; k < 8; k++) {
                    int curx = i + dx[k];
                    int cury = j + dy[k];
                    if (curx >= 0 && curx < board.size() && cury >= 0 && cury < board.size()) {
                        if (board[curx][cury] != 1) board[curx][cury] = 2;                   //�������밡 �ƴ϶�� ���ڰ� �ִ°� �ƴ϶� 1���� �ٸ������� �Ҵ�
                    }
                }
            }
        }
    }

    for (int i = 0; i < board.size(); i++) {            //��ȸ�ϸ鼭 
        for (int j = 0; j < board[0].size(); j++) {         //��,�Ʒ�,��,��,�밢���� ���ڰ� �ִٸ� ��������
            if (board[i][j] == 0) answer++;
        }
    }
    return answer;
}