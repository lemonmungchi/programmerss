#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�׸����ϰ� ����
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    int end = targets[0][1];
    answer++;
    for (int i = 1; i < targets.size(); i++) {
        //���� ���۰��� �����ص� �������� �۴ٸ� ��ݰ���
        if (targets[i][0] < end) continue;
        //�ƴ϶�� ���ο� �������Ʈ ����
        else {
            answer++;
            end = targets[i][1];
        }
    }
    return answer;
}