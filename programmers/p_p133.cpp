#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, int> m1;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        m1[i] = 1;
    }

    for (int i = 0; i < reserve.size(); i++) {
        m1[reserve[i]] = 2;
    }
    for (int i = 0; i < lost.size(); i++) {
        m1[lost[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        if (m1[i] == 0) {
            if (m1[i - 1] == 2) {
                m1[i - 1]--;
                m1[i]++;
            }
            else if (m1[i + 1] == 2) {
                m1[i + 1]--;
                m1[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (m1[i] >= 1) {
            answer++;
        }
    }
    return answer;
}