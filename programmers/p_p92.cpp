#include <string>
#include <vector>

using namespace std;
//4���� ����� �ľ� -> ���� -> ������ �̵�-> �ٽ� �ľ�-> �ݺ�
void fillEmpty(int m, int n, vector<string>& board) {  //������� �����ִ� �Լ�
    for (int j = 0; j < n; j++) {
        string tmp = "";
        for (int i = m - 1; i >= 0; i--) if (board[i][j] != ' ') tmp += board[i][j];     //ä�����ִ� ĭ�̶�� tmp�� ��� �߰�
        int i = m - 1;          //�� ����������
        for (auto c : tmp) board[i--][j] = c;       //tmp���� �ϳ��� ������ ���ؿ������� �߰�
        for (; i >= 0; i--) board[i][j] = ' ';         //�������� ��ĭ����
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
    vector<vector<bool>> vis(m, vector<bool>(n, false)); //2���� bool���� ���� �� �ʱ�ȭ

    while (1) {
        bool done = true;
        fill(vis.begin(), vis.end(), vector<bool>(n, false)); //2���� bool ���� �ʱ�ȭ
        for (int i = 0; i < m - 1; i++) {         //�񱳸� ���� m-1,n-1����
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] != ' ' && is_erase(i, j, board, vis)) done = false;
                //������ �ƴϰ� ���� �� �ִٸ� �湮üũ �� �������
            }
        }
        if (done) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) board[i][j] = ' '; //�湮ó����=> �� ���� �� �ִ� ĭ�� �����.
            }
        }
        fillEmpty(m, n, board); //����� ������
    }
    for (auto s : board) {
        for (auto c : s) if (c == ' ') answer++; //��ĭ�� ��� ������������� �߰�
    }

    return answer;
}