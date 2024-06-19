#include <cmath>
using namespace std;
//�밢���� w���� ���� ���ڼ��� h���� ���� ���ڼ��� ��� ���� W+H���� ��輱�� ������ �ȴ�.
//������ �ִ�������ŭ �߻�
//��輱- �ߺ��� ������
int getGCD(long long w, long long h) {
    int small, big;
    if (w > h) {
        big = w;
        small = h;
    }
    else {
        big = h;
        small = w;
    }
    int mod = big % small;
    while (mod > 0) {
        big = small;
        small = mod;
        mod = big % small;
    }

    return small;
}

long long solution(int w, int h) {
    long long answer;
    long long W = w;
    long long H = h;

    int gcd = getGCD(W, H);
    long long total = W * H;
    answer = total - (W + H - gcd);
    return answer;
}