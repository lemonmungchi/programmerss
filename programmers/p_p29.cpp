#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, int> m;
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    char u[8] = { 'R','T','C','F','J','M','A','N' };
    for (int i = 0; i < 8; i++) {
        m[u[i]] = 0;
    }

    for (int i = 0; i < survey.size(); i++) {
        switch (choices[i]) {
        case 1:
            m[survey[i][0]] += 3;
            break;
        case 2:
            m[survey[i][0]] += 2;
            break;
        case 3:
            m[survey[i][0]] += 1;
            break;
        case 4:
            break;
        case 5:
            m[survey[i][1]] += 1;
            break;
        case 6:
            m[survey[i][1]] += 2;
            break;
        case 7:
            m[survey[i][1]] += 3;
            break;
        }
    }

    for (int i = 0; i < m.size();) {
        if (m[u[i]] > m[u[i + 1]]) {
            answer += u[i];
        }
        else if (m[u[i]] < m[u[i + 1]]) {
            answer += u[i + 1];
        }
        else if (m[u[i]] == m[u[i + 1]]) {
            answer += u[i];
        }
        i += 2;
    }
    return answer;
}