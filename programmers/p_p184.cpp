#include <string>
#include <vector>
//��ȸ�ϸ鼭 �ڸ��� ���� ������Ű�鼭 ���ڿ� ��
using namespace std;
int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {                //i�� ���ڿ��� �ڸ��� ����
        int cnt = 1;                  //��ġ�°� ����
        string tmp = "", a = "";        //����� ����, �ڸ� ����
        a = s.substr(0, i);
        for (int j = i; j < s.size(); j += i) {           //�ڸ���ŭ ��ȸ
            if (a == s.substr(j, i)) cnt++;             //���� ��ġ�°� �ִٸ� 
            else {
                if (cnt > 1) tmp += to_string(cnt);
                tmp += a;
                a = s.substr(j, i);                //������ �˻��� �κ�
                cnt = 1;                  //���������� �ٽ� ��ġ�°� ã������ 1�� �ʱ�ȭ
            }
        }
        if (cnt > 1) tmp += to_string(cnt);
        tmp += a;
        if (answer > tmp.size())answer = tmp.size();
    }
    return answer;
}