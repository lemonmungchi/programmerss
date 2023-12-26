#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = n;
    vector<int> three;
    while (a) {
        three.push_back(a % 3);
        a /= 3;
    }
    int mul = 1;
    for (int i = three.size() - 1; i >= 0; i--) {
        answer += three[i] * mul;
        mul *= 3;
    }
    return answer;
}