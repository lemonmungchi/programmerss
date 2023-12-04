#include <string>
#include <vector>
#include <cmath>

using namespace std;

int find_measure(int n) {
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum++;
            if (i != n / i)sum++;
        }
    }
    return sum;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        if (find_measure(i) % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}