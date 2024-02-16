#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int r;

    while (storey > 0) {
        r = storey % 10;           //������
        storey = storey / 10;      //10���� ���� ������ => ������ ���ֱ� �ڸ��� ���� => �ٽ� �÷������
        if (r > 5 || (r == 5 && storey % 10 >= 5)) {     //5���� ũ�ų� 5�� ������ ���� ���� �ٽ� �������� 5���� ũ��
            answer += 10 - r;               //5���� ũ�� 10���� ���� ���ϴ°� �� ����
            storey++;               //�ڸ��� �ϳ� �ø���
        }
        else {              //5���� ������ �׳� ���ϴ°� ����
            answer += r;
        }
    }
    return answer;
}