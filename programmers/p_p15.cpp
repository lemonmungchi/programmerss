#include <string>
#include <vector>
#include <cmath>

using namespace std;

int factor(int a) {
    if (a <= 0) {
        return 0;
    }
    int n = 0;
    for (int i = 1; i <= sqrt(a); i++)
        if (a % i == 0)
        {
            n++;
            if (i != a / i) n++;
        }
    return n;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> n;
    for (int i = 1; i <= number; i++) {
        n.push_back(factor(i));
    }
    for (int i = 0; i < n.size(); i++) {
        if (n[i] > limit) n[i] = power;
    }
    for (int i = 0; i < n.size(); i++) {
        answer += n[i];
    }
    return answer;
}