#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//그리디하게 접근
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    int end = targets[0][1];
    answer++;
    for (int i = 1; i < targets.size(); i++) {
        //만약 시작값이 설정해둔 끝점보다 작다면 요격가능
        if (targets[i][0] < end) continue;
        //아니라면 새로운 요격포인트 지정
        else {
            answer++;
            end = targets[i][1];
        }
    }
    return answer;
}