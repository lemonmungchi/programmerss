#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (a % 2 == 1) a++;            //Ȧ����°�� ������ 1�� ������� ��
        if (b % 2 == 1) b++;

        a /= 2;                        
        b /= 2;
        if (a == b) break;              //�������� �������� �������� �ִ°���
    }
    return i;
}