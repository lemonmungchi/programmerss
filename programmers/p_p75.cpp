#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(long long value) {
    if (value < 2) return false;

    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    //k진수 구하는 공식
    string s = "";
    while (n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());

    //소수구하기
    string tmp = "";
    for (auto c : s) {
        if (c == '0') {                             //0을기준으로 split 
            if (!tmp.empty() && isPrime(stoll(tmp))) {
                answer++;
            }
            tmp = "";                     //초기화
        }
        else {
            tmp += c;                     //0이 아닌경우에는 문자열에 더해서 숫자만들기
        }

    }

    if (!tmp.empty() && isPrime(stoll(tmp))) {          //마지막 수 
        answer++;
    }

    return answer;
}