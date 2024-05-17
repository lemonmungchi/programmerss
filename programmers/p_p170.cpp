#include <string>
#include <vector>
#include <algorithm>
//핵심 : 한그룹의 최대공약수로 다른 그룹을 나눴을 때 안 나눠지는게 있는가
using namespace std;
int gcd(int a, int b) {               //최대공약수 구하기
    if (b == 0) return a;
    return gcd(b, a % b);
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int cur = arrayA[0];
    for (int i = 1; i < arrayA.size(); i++) {
        cur = gcd(cur, arrayA[i]);
        if (cur == 1) break;
    }
    if (cur != 1) {
        int cnt;
        for (cnt = 0; cnt < arrayB.size(); cnt++) {
            if (arrayB[cnt] % cur == 0) break;
        }
        if (cnt == arrayB.size()) answer = cur;
    }

    cur = arrayB[0];
    for (int i = 1; i < arrayB.size(); i++) {
        cur = gcd(cur, arrayB[i]);
        if (cur == 1) break;
    }
    if (cur != 1) {
        int cnt;
        for (cnt = 0; cnt < arrayA.size(); cnt++) {
            if (arrayA[cnt] % cur == 0) break;
        }
        if (cnt == arrayA.size()) answer = max(cur, answer);        //만약 두 그룹 다 조건에 만족하는 수가 있다면 그 중에 큰 수가 정답
    }
    return answer;
}