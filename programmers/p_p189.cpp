#include <string>
#include <vector>
#include <cmath>
using namespace std;
//�� ��и��� ���� ã�Ƽ� 4�� �����ֱ� 
long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i <= r2; i++) {
        int maxY = floor(sqrt((long long)r2 * r2 - (long long)i * i));            //�ִ� Y�� �����ؾ� �������� ������ ���� �� �ִ�.
        int minY = ceil(sqrt((long long)r1 * r1 - (long long)i * i));             //�ּ� Y�� �ø��ؾ� ���ٷ� �ٱ��ʱ����� ���� ���� �� �ִ�.

        if (r1 < i) minY = 0;            //x���� r1���� ũ�� �����̿��� �ּ�y�� 0���� ����

        answer += (maxY - minY + 1);

    }
    return answer * 4;
}