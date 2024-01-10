#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            ans++;
        }
        n /= 2;       //순간이동한결과를 반환
    }
    return ans;
}