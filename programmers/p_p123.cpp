#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int c;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            c = s[i] + n;
            if (c > 'z') {
                c -= 26;
            }
            s[i] = (char)c;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            c = s[i] + n;
            if (c > 'Z') {
                c -= 26;
            }
            s[i] = (char)c;
        }
    }
    answer = s;
    return answer;
}