#include <string>
#include <vector>
#include <algorithm>
int answer = 50;
bool visited[50];

using namespace std;

bool diff_st(string a, string b) {            //두 문자열 비교해서 다른 문자가 1개인지 판별
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
        answer = min(answer, cnt);                 //answer은 최대길이 값보다 작은 것 중에 최소값
        return;
    }


    for (int i = 0; i < words.size(); i++) {
        if (diff_st(begin, words[i]) && !visited[i]) {                //다른 문자가 한개라면
            visited[i] = true;
            dfs(words[i], target, words, cnt + 1);
            visited[i] = false;
        }
    }

    return;
}
int solution(string begin, string target, vector<string> words) {

    dfs(begin, target, words, 0);

    if (answer == 50) {             //만약 모두를 탐색했는데도 target에 도달하지 못했을 경우
        return 0;
    }
    return answer;
}