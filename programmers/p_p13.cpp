#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i, j;
    for (i = 0; i < s.length(); i++) {
        int count_a = 0;
        int count_b = 0;
        char a = s[i];
        for (j = i; j < s.length(); j++) {
            if (s[i] == s[j]) {
                count_a++;
            }
            else {
                count_b++;
            }

            if (count_a == count_b) break;
        }
        i = j;
        answer++;
    }
    return answer;
}