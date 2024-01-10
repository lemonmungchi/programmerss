#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for (int h = 3; h <= sqrt(sum); h++) {
        if (sum % h == 0) {
            int w = sum / h;

            if ((w - 2) * (h - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
            }
        }
    }
    return answer;
}