#include <string>
#include <vector>
#include <cmath>

using namespace std;
//�ִ��� 0,d d,0 �ȿ��� ���ǵǴ� ���� ���� 
long long solution(int k, int d) {
    long long answer = 0;
    for (long long x = 0; x <= d; x += k) {           //x�� ���� y�� ���
        int maxy = sqrt((long long)d * d - (long long)x * x);       //x���� ���� y�� �ִ밪 ���
        answer += (maxy / k) + 1;         //y�� �ִ밪�� ���� x�� ���� ���-> ��ǥ ���� 
        //+1�� ����: y�� 0�϶��� ���Խ�Ű����
    }
    return answer;
}