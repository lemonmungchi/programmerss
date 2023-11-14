#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int len = s.length();
    int an = -1;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                an = i - j;
            }
        }
        answer.push_back(an);

    }
    return answer;
}