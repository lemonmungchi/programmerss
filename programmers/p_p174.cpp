#include <string>
#include <vector>
#include <stack>

using namespace std;
//�ùٸ� ��ȣ ���ڿ� �˻�
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

    for (int i = 0; i < p.length(); i++) {          //��ȣ�� ���� �˻�
        if (p[i] == '(') left++;
        else right++;

        if (left == right) {                //���� ��ȣ�� ������ ���ٸ� �������� ��ȣ ���ڿ�
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if (check(u))answer = u + solution(v);           //���� ���ڿ����� u�� �ùٸ� ���ڿ����� Ȯ��
    else {
        answer = '(' + solution(v) + ')';             //4-1~4-3

        for (int i = 1; i < u.length() - 1; i++) {            //4-4 �� �ڷ� ()�� �ٿ����� 1~ len-1���� 
            answer += u[i] == '(' ? ')' : '(';              //3�׿����ڷ� ( �̸� )�� �ٲٰ� �ƴϸ� (�� �ٲ��ֱ�
        }
    }


    return answer;
}