#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;


    for (int i = 0; i < s.length(); i++) {                  //회전 반복문
        stack<char> stk;
        bool flag = false;
        for (int j = 0; j < s.length(); j++) {              //검사 반복문
            if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
                flag = true;
                stk.push(s[j]);
            }
            else {
                if (s[j] == '}' && stk.top() == '{') {
                    stk.pop();
                }
                if (s[j] == ']' && stk.top() == '[') {
                    stk.pop();
                }
                if (s[j] == ')' && stk.top() == '(') {
                    stk.pop();
                }
            }
        }

        if (stk.empty() && flag) answer++;

        char temp = s.front();                  //회전-> 앞에껄 젤 뒤로 옮기기
        s.erase(s.begin());
        s.push_back(temp);

    }


    return answer;
}