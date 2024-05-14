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

    for (int i = 1; i <= n; i++) {              //Ʈ���̾ޱ� ��� ����ֱ�
        vector<int>tmp;
        for (int j = 0; j < i; j++) tmp.push_back(0);
        triangle.push_back(tmp);
    }

    int col = 0, row = 0;
    int num = 1;
    int turn = 0;                 //turn �Ѵܰ谡 �������� ���� -> ���� �� �� �ִ� �� ����, ��ü-turn �ݺ�Ƚ��
    while (true) {
        if (triangle[col][row] > 0) break;          //���� ä�����ִ� ĭ�̶�� ��

        for (int i = col; i < n - turn; i++) {            //�Ʒ��� �̵� 
            if (triangle[i][turn] == 0) {
                triangle[i][turn] = num++;
                col = i; row = turn;
            }
            else break;
        }
        row += 1; turn += 1;        //ä�����ִ� �� ���� �κк��� 

        for (int j = row; j <= n - turn; j++) {            //���������� �̵� 
            if (triangle[n - turn][j] == 0) {             //
                triangle[n - turn][j] = num++;
                col = n - turn; row = j;
            }
            else break;
        }
        col -= 1;         //ä�����ִ°� ���� ����

        for (int k = col; k >= turn; k--) {         //��~ä������ �ձ��� ����
            if (triangle[k][k - turn + 1] == 0) {              //k~1��° ����
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