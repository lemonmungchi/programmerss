#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int>m1;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i < want.size(); i++) {
        m1[want[i]] = number[i];
    }
    for (int i = 0; i < discount.size(); i++) {                //일정 하나씩 검사
        map<string, int>m2;
        for (int j = i; j < i + 10; j++) {                     //현재일정에서 10일까지 검사
            m2[discount[j]] += 1;
            if (j == discount.size() - 1) break;
        }
        if (m2 == m1) answer++;                             //map 두개가 같은가 -> 두개의 값이 같은가
    }
    return answer;
}