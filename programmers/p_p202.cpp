#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
//dp활용 
//짝수일때만 계산가능

int solution(int n) {
    if (n % 2 != 0) return 0; // 홀수일 경우 0 반환

    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // base case
    dp[2] = 3; // 기본적인 2x3 타일 배치 방법의 수

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] %= MOD;
    }

    return dp[n];
}