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

    //k���� ���ϴ� ����
    string s = "";
    while (n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());

    //�Ҽ����ϱ�
    string tmp = "";
    for (auto c : s) {
        if (c == '0') {                             //0���������� split 
            if (!tmp.empty() && isPrime(stoll(tmp))) {
                answer++;
            }
            tmp = "";                     //�ʱ�ȭ
        }
        else {
            tmp += c;                     //0�� �ƴѰ�쿡�� ���ڿ��� ���ؼ� ���ڸ����
        }

    }

    if (!tmp.empty() && isPrime(stoll(tmp))) {          //������ �� 
        answer++;
    }

    return answer;
}