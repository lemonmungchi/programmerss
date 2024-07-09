#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int MAX_VALUE = 10000000;

long long FindMaxDiv(int num)
{
    long long result = 1;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            result = i;

            if (num / i <= MAX_VALUE) {
                result = num / i;
                break;
            }
        }
    }

    return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (int i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        answer.push_back(FindMaxDiv(i));
    }
    return answer;
}