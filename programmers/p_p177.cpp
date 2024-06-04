#include <string>
#include <vector>
#include <algorithm>
int board[101][101];
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt = 1;
    for (int i = 1; i <= rows; i++) {           //������ �ʱ�ȭ
        for (int j = 1; j <= columns; j++) {
            board[i][j] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        vector<int> nums;           //���� ���ڸ� ����
        vector<pair<int, int>> xy;   //���ڵ��� ��ǥ���� ����
        int mn = 1e9;
        int sty = queries[i][0];      //����,�� ��ǥ
        int stx = queries[i][1];
        int edy = queries[i][2];
        int edx = queries[i][3];
        //���� ������� �������� ����->�Ʒ�->��->��
        //����
        for (int x = stx + 1; x <= edx; x++) {
            nums.push_back(board[sty][x]);
            mn = min(mn, board[sty][x]);
            xy.push_back({ sty,x });
        }
        //�Ʒ�
        for (int y = sty + 1; y <= edy; y++) {
            nums.push_back(board[y][edx]);
            mn = min(mn, board[y][edx]);
            xy.push_back({ y,edx });
        }
        //��
        for (int x = edx - 1; x >= stx; x--) {
            nums.push_back(board[edy][x]);
            mn = min(mn, board[edy][x]);
            xy.push_back({ edy,x });
        }
        //��
        for (int y = edy - 1; y >= sty; y--) {
            nums.push_back(board[y][stx]);
            mn = min(mn, board[y][stx]);
            xy.push_back({ y,stx });
        }
        rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());          //�ð���� ȸ��

        for (int x = 0; x < xy.size(); x++) {
            board[xy[x].first][xy[x].second] = nums[x];                 //ȸ���� ���͸� �ڸ����� ����
        }

        answer.push_back(mn);                               //�ּҰ� ����
    }

    return answer;
}