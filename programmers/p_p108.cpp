#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_num = 0;
    int y_num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (tolower(s[i]) == 'p') {
            p_num++;
        }
        else if (tolower(s[i]) == 'y') {
            y_num++;
        }
    }
    if (p_num == y_num) {
        answer = true;
    }
    else {
        answer = false;
    }
    return answer;
}