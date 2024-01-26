#include <string>
#include <vector>
#include <stack>

using namespace std;

string makestr(int n, int max) {          //n����, max�� ���� �ִ밪 => t*m 
    string str = "";
    stack<int> s;               //�߰��� ���� ������ ���ú���

    for (int i = 0; str.length() <= max; i++) {
        int x = i;

        while (1) {
            s.push(x % n);
            x /= n;

            if (x == 0) break;
        }

        while (!s.empty()) {
            if (s.top() < 10) {
                str += to_string(s.top());
            }
            else {
                str += (char)(65 + s.top() - 10);     //10���� ũ�ٸ� A~F�� ��ȯ
            }
            s.pop();
        }
    }

    return str;

}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string str = makestr(n, m * t);

    for (int i = p - 1; t > 0; i += m) {
        answer += str[i];
        t--;
    }
    return answer;
}