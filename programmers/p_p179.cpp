#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cmpnum;
bool cmp(vector<int> a, vector<int> b) {
    if (a[cmpnum] == b[cmpnum]) {      //���� col��° ���� ���� ���ٸ�
        // �⺻Ű (ù ��° ��) ���� �������� ����
        return a[0] > b[0];
    }

    return a[cmpnum] < b[cmpnum]; //�ƴ϶�� 
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    cmpnum = col - 1;           //col��° ��
    sort(data.begin(), data.end(), cmp);          //�������� ����

    for (int i = row_begin - 1; i < row_end; i++) {
        int sum = 0;
        for (int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        answer ^= sum;               //������ ���� ��� xor���ֱ�
    }

    return answer;
}