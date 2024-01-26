#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string words = "AEIOU";           //사전 전체문자열
void dfs_str(string start, string target) {
    cnt++;                          //함수가 호출될때마다 사전의 순서가 뒤로 밀린다=> cnt= 사전상의 순서

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