#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//�ᱹ�� �׸���
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int delivery_load = 0;  // ���� Ʈ���� �Ǹ� ��� ���� ��
    int pickup_load = 0;    // ���� Ʈ���� �Ǹ� ���� ���� ��

    // ���� �� ������ ��ȸ
    for (int i = n - 1; i >= 0; --i) {
        // �ش� ���� ����ϰų� ������ ���ڰ� �ִ� ��쿡�� �۾�
        if (deliveries[i] > 0 || pickups[i] > 0) {
            int rounds = 0;  // �ش� ���� ���� �պ� Ƚ��

            // ��� �Ǵ� ������ ���ڰ� Ʈ�� �뷮���� ���� ��� �߰��� �պ��ؾ� ��
            while (delivery_load < deliveries[i] || pickup_load < pickups[i]) {
                rounds++;
                delivery_load += cap;  // Ʈ���� �ִ� �뷮��ŭ ��� ���ڸ� �߰��� ����
                pickup_load += cap;    // Ʈ���� �ִ� �뷮��ŭ ���� ���ڸ� �߰��� ����
            }

            // �ش� ������ ����� ���ڸ� Ʈ������ ����
            delivery_load -= deliveries[i];
            // �ش� ������ ������ �� ���ڸ� Ʈ���� ����
            pickup_load -= pickups[i];

            // �պ� �Ÿ��� �信 �߰� (�������� �Ÿ� * 2 * �պ� Ƚ��)
            answer += (i + 1) * 2 * rounds;
        }
    }

    return answer;
}
