#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tcountf = 0;
    int tcounts = 0;
    int i = n;
    while (i >= 1) {
        if (i % 2 == 1) {
            tcountf++;
        }
        i /= 2;
    }
    i = n;
    while (true) {
        i++;
        int j = i;
        tcounts = 0;
        while (j >= 1) {
            if (j % 2 == 1) {
                tcounts++;
            }
            j /= 2;
        }
        if (tcountf == tcounts) {
            answer = i;
            break;
        }
    }
    return answer;
}