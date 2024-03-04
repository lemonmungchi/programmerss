#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) return a.second < b.second;            //������ ���ٸ� ���� ū ������
    else return a.first > b.first;
}

int cnt[501];            //���������� Ŭ�������� ���� ����� ��
vector<pair<double, int>> failure;           //�����̺� ������ ������ ����
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int st = stages.size();
    for (int i = 0; i < st; i++) {
        cnt[stages[i]]++;           //���������� Ŭ�������� ���� ����� �� ����
    }
    int tmp = st;
    for (int i = 1; i <= N; i++) {

        if (cnt[i] == 0) failure.push_back({ 0,i });     //������ ����� ���ٸ� �������� 0
        else {
            double t = (double)cnt[i] / tmp;             //������ ���

            failure.push_back({ t,i });
        }

        tmp -= cnt[i];         //�ش�ܰ迡�� �����ߴٸ� �����ܰ赵 ���� �� �ο� ���̱�
    }
    sort(failure.begin(), failure.end(), compare);

    int fsize = failure.size();

    for (int i = 0; i < fsize; i++) {
        auto p = failure[i];
        answer.push_back(p.second);
    }

    return answer;
}