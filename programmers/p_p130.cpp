#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> v(n + 1, true);

    for (int i = 2; i <= n; i++) {              //전체 순회
        if (v[i]) {               //소수라면
            for (int j = 2; j * i <= n; j++) {            //배수 찾기
                v[i * j] = false;               //배수는 소수가 아니다.
            }
            answer++;
        }
    }
    return answer;
}