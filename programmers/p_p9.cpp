#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int len = s.length();
    int an;
    for (int i = 0; i < s.length(); i++) {
        char a = s[i];
        if (i == 0) {
            answer.push_back(-1);
        }
        else {
            for (int j = i-1; j < 0; j--) {
                if (a == s[j]) {
                    an = min(j, len);
                    len = j;
                }
            }
            if (an == len) {
                answer.push_back(-1);
            }
            answer.push_back(an);
        }  
    }
    return answer;
}