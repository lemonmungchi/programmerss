#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m;
int fatigue[3][3] = { {1,1,1}, {5,1,1}, {25,5,1} }; // [곡괭이로][해당 광물 캘 때] = 드는 피로도
//하나의 곡괭이로 계속해서 캐야함 => DFS
void DFS(vector<int>& picks, vector<string>& minerals, int& answer, int sum, int location) {
    // 광물을 다 캤거나 곡괭이를 다 썼을 때 피로도를 갱신
    if (location == minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)) {
        answer = min(answer, sum);
        return;
    }

    // 0~2 곡괭이 방문
    for (int i = 0; i < 3; i++) {
        // i 곡괭이가 있다면
        if (picks[i] != 0) {
            picks[i]--;

            int tmpIdx = location; //캐야 할 광물의 임시 인덱스
            int tmpSum = sum; // 광물을 캐며 누적된 임시 피로도
            for (; tmpIdx < location + 5 && tmpIdx < minerals.size(); tmpIdx++) { // 5개를 캐거나 끝까지 캘 때까지
                tmpSum += fatigue[i][m[minerals[tmpIdx]]]; // 계속 광물을 캐기 피로도 누적
            }

            DFS(picks, minerals, answer, tmpSum, tmpIdx);

            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = (25 * 50) + 1; // 최고 피로도 * 최대 광물 개수

    m.insert({ "diamond", 0 });
    m.insert({ "iron", 1 });
    m.insert({ "stone", 2 });

    DFS(picks, minerals, answer, 0, 0);

    return answer;
}