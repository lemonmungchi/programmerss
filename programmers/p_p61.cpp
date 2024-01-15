#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;


    for (int i = 0; i < s.length(); i++) {                  //ȸ�� �ݺ���
        stack<char> stk;
        bool flag = false;
        for (int j = 0; j < s.length(); j++) {              //�˻� �ݺ���
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

        char temp = s.front();                  //ȸ��-> �տ��� �� �ڷ� �ű��
        s.erase(s.begin());
        s.push_back(temp);

    }


    return answer;
}