#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        for (int j = 0; j < index; j++) {
            c += 1;
            if (c == 'z' + 1) c = 'a';
            for (int a = 0; a < skip.length(); a++) {
                if (skip.find(c) != string::npos) {
                    c += 1;
                    if (c > 'z') {
                        c = 'a';
                    }
                }
            }
        }
        answer += c;
    }
    return answer;
}
