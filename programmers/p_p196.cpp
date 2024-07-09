#include <string>
#include <algorithm>
using namespace std;
//���ĺ� ���� �����̻��̸� �������� �̵��ϴ°��� �̵�, �ƴ϶�� ���������� �̵��ϴ°��� �̵�
//Ŀ���� �����ϰ� ������ �����̻��̸� �������� �̵��ϴ� ���� �̵�, �ƴ϶�� ���������� �̵�
int solution(string name) {
    int n = name.length();
    int answer = 0;

    // �� ���ĺ��� �ٲٴ� �� �ʿ��� ���� Ƚ���� �ջ�
    for (int i = 0; i < n; ++i) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    // Ŀ�� �̵��� �ּ� ���� Ƚ���� ����
    int move = n - 1;
    for (int i = 0; i < n; ++i) {
        int next = i + 1;
        while (next < n && name[next] == 'A') {         //A�ǳʶٱ� 
            ++next;
        }
        move = min(move, i + n - next + min(i, n - next));      //�������� ����, ���������� ���� ��
    }

    return answer + move;
}
