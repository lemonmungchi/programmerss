#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m1;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < participant.size(); i++) {
        m1[participant[i]]++;
    }
    for (int i = 0; i < completion.size(); i++) {
        m1[completion[i]]--;
    }
    for (int i = 0; i < participant.size(); i++) {
        if (m1[participant[i]] >= 1) {
            answer += participant[i];
            m1[participant[i]]--;
        }
    }
    return answer;
}