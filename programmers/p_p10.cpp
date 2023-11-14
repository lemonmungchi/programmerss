#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len = p.length();
    for (int i = 0; i <= t.length() - len; i++) {
        string a = t.substr(i, len);
        long an = stol(a);
        if (an <= stol(p)) answer += 1;
    }
    return answer;
}