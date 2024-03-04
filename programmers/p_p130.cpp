#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> v(n + 1, true);

    for (int i = 2; i <= n; i++) {              //��ü ��ȸ
        if (v[i]) {               //�Ҽ����
            for (int j = 2; j * i <= n; j++) {            //��� ã��
                v[i * j] = false;               //����� �Ҽ��� �ƴϴ�.
            }
            answer++;
        }
    }
    return answer;
}