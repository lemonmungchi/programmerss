#include <string>
#include <algorithm>
using namespace std;
//알파벳 기준 절반이상이면 왼쪽으로 이동하는것이 이득, 아니라면 오른쪽으로 이동하는것이 이득
//커서도 동일하게 길이의 절반이상이면 왼쪽으로 이동하는 것이 이득, 아니라면 오른쪽으로 이동
int solution(string name) {
    int n = name.length();
    int answer = 0;

    // 각 알파벳을 바꾸는 데 필요한 조작 횟수를 합산
    for (int i = 0; i < n; ++i) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    // 커서 이동의 최소 조작 횟수를 구함
    int move = n - 1;
    for (int i = 0; i < n; ++i) {
        int next = i + 1;
        while (next < n && name[next] == 'A') {         //A건너뛰기 
            ++next;
        }
        move = min(move, i + n - next + min(i, n - next));      //왼쪽으로 갈때, 오른쪽으로 갈때 비교
    }

    return answer + move;
}
