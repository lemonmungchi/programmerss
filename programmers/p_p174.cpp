#include <string>
#include <vector>
#include <stack>

using namespace std;
//올바른 괄호 문자열 검사
bool check(string s) {
    stack<char> st;

    for (auto c : s) {
        if (c == '(') st.push(c);
        else {
            if (st.empty())return false;
            st.pop();
        }
    }

    return st.empty();
}
string solution(string p) {
    string answer = "";
    if (p == "") return "";

    string u = "", v = "";
    int left = 0, right = 0;

    for (int i = 0; i < p.length(); i++) {          //괄호의 갯수 검사
        if (p[i] == '(') left++;
        else right++;

        if (left == right) {                //만약 괄호의 개수가 같다면 균형잡힌 괄호 문자열
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if (check(u))answer = u + solution(v);           //나눈 문자열에서 u가 올바른 문자열인지 확인
    else {
        answer = '(' + solution(v) + ')';             //4-1~4-3

        for (int i = 1; i < u.length() - 1; i++) {            //4-4 앞 뒤로 ()를 붙였으니 1~ len-1까지 
            answer += u[i] == '(' ? ')' : '(';              //3항연산자로 ( 이면 )로 바꾸고 아니면 (로 바꿔주기
        }
    }


    return answer;
}