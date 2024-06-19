#include <cmath>
using namespace std;
//대각선은 w개의 가로 격자선과 h개의 세로 격자선을 통과 따라서 W+H개의 경계선을 지나게 된다.
//교차점 최대공약수만큼 발생
//경계선- 중복된 교차점
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