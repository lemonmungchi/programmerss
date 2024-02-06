#include <string>
#include <vector>

using namespace std;
int d[60001];
int solution(int n) {
    int answer = 0;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] = d[i] % 1000000007;
    }
    answer = d[n];
    return answer;
}