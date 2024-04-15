#include <string>
#include <vector>

using namespace std;
long long factorial(long long num) {     //���丮�� ����Լ�����
    if (num == 1)
        return 1;
    return factorial(num - 1) * num;
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    long long now = k;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        num.push_back(i);
    }

    while (cnt != n) {
        long long tmp = factorial(n - cnt);           //n���� �ڸ����� (k-1)/(n-1)!
        int idx = (now - 1) / tmp;
        answer.push_back(num[idx]);
        num.erase(num.begin() + idx);
        cnt++;
        now %= tmp;               //k�� ���� ���� ������Ʈ
        if (now == 0) {         //k�� 0�̶�� (n-1)!������
            now = tmp;
        }
    }
    answer.push_back(num[0]);
    return answer;
}