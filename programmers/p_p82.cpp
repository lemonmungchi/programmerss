#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string words = "AEIOU";           //���� ��ü���ڿ�
void dfs_str(string start, string target) {
    cnt++;                          //�Լ��� ȣ��ɶ����� ������ ������ �ڷ� �и���=> cnt= �������� ����

    if (start == target) {
        answer = cnt;
        return;
    }

    if (start.length() >= 5) return;

    for (int i = 0; i < words.length(); i++) {
        dfs_str(start + words[i], target);
    }

}

int solution(string word) {
    dfs_str("", word);
    return answer;
}