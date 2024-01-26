#include <string>
#include <vector>
#include <algorithm>
int answer = 50;
bool visited[50];

using namespace std;

bool diff_st(string a, string b) {            //�� ���ڿ� ���ؼ� �ٸ� ���ڰ� 1������ �Ǻ�
    int diff = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    if (diff == 1) {
        return true;
    }
    else return false;
}
void dfs(string begin, string target, vector<string> words, int cnt) {
    if (answer <= cnt) {
        return;
    }

    if (begin == target) {
        answer = min(answer, cnt);                 //answer�� �ִ���� ������ ���� �� �߿� �ּҰ�
        return;
    }


    for (int i = 0; i < words.size(); i++) {
        if (diff_st(begin, words[i]) && !visited[i]) {                //�ٸ� ���ڰ� �Ѱ����
            visited[i] = true;
            dfs(words[i], target, words, cnt + 1);
            visited[i] = false;
        }
    }

    return;
}
int solution(string begin, string target, vector<string> words) {

    dfs(begin, target, words, 0);

    if (answer == 50) {             //���� ��θ� Ž���ߴµ��� target�� �������� ������ ���
        return 0;
    }
    return answer;
}