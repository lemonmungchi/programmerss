#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> se;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') se.push('(');
        else {
            if (!se.empty() && se.top() == '(') {
                se.pop();
            }
            else {
                se.push(')');
            }
        }
    }

    if (se.empty()) {
        return true;
    }
    else {
        return false;
    }
}