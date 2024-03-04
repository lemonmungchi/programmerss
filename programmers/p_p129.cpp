#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int m1[] = { 1,2,3,4,5 };
    int m2[] = { 2,1,2,3,2,4,2,5 };
    int m3[] = { 3,3,1,1,2,2,4,4,5,5 };
    int m1cnt = 0;
    int m2cnt = 0;
    int m3cnt = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (m1[i % 5] == answers[i]) m1cnt++;
        if (m2[i % 8] == answers[i]) m2cnt++;
        if (m3[i % 10] == answers[i]) m3cnt++;
    }

    int maxnum = max(m1cnt, m2cnt);
    maxnum = max(maxnum, m3cnt);
    if (maxnum == m1cnt) answer.push_back(1);
    if (maxnum == m2cnt) answer.push_back(2);
    if (maxnum == m3cnt) answer.push_back(3);
    return answer;
}