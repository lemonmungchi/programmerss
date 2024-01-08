#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> v(100000, 0);
    v[0] = 0;
    v[1] = 1;
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 1234567;           //오버플로우 방지 미리 나누어주기
    }
    return v[n];
}