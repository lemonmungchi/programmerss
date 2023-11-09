#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    pair<int, int>m1;
    m1.first = section[0];
    m1.second = section[0] + m - 1;
    answer = 1;

    for (int i = 0; i < section.size(); i++) {
        if (m1.second < section[i]) {
            answer++;
            m1.first = section[i];
            m1.second = section[i] + m - 1;
        }
    }
    return answer;
}