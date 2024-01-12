#include <string>
#include <vector>

using namespace std;

long long solution(int n) {         //피보나치 수열을 DP로 풀면 된다.
    long long arr[2001];
    arr[0] = 1;               //0일때 1가지 
    arr[1] = 1;               //1일때 1가지       2일때 1+1 2 2가지 3일때 1+1 2+1 1+2 3가지(2+1)
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;
    }

    return arr[n];
}