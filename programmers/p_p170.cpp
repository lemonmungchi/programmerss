#include <string>
#include <vector>
#include <algorithm>
//�ٽ� : �ѱ׷��� �ִ������� �ٸ� �׷��� ������ �� �� �������°� �ִ°�
using namespace std;
int gcd(int a, int b) {               //�ִ����� ���ϱ�
    if (b == 0) return a;
    return gcd(b, a % b);
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int cur = arrayA[0];
    for (int i = 1; i < arrayA.size(); i++) {
        cur = gcd(cur, arrayA[i]);
        if (cur == 1) break;
    }
    if (cur != 1) {
        int cnt;
        for (cnt = 0; cnt < arrayB.size(); cnt++) {
            if (arrayB[cnt] % cur == 0) break;
        }
        if (cnt == arrayB.size()) answer = cur;
    }

    cur = arrayB[0];
    for (int i = 1; i < arrayB.size(); i++) {
        cur = gcd(cur, arrayB[i]);
        if (cur == 1) break;
    }
    if (cur != 1) {
        int cnt;
        for (cnt = 0; cnt < arrayA.size(); cnt++) {
            if (arrayA[cnt] % cur == 0) break;
        }
        if (cnt == arrayA.size()) answer = max(cur, answer);        //���� �� �׷� �� ���ǿ� �����ϴ� ���� �ִٸ� �� �߿� ū ���� ����
    }
    return answer;
}