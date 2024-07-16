#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 점수를 계산하는 함수
int calculateScore(const vector<int>& info, const vector<int>& ryan) {
    int apeach_score = 0, ryan_score = 0;
    for (int i = 0; i < 11; i++) {
        if (info[i] == 0 && ryan[i] == 0) {
            continue;
        }
        if (info[i] >= ryan[i]) {
            apeach_score += 10 - i;
        }
        else {
            ryan_score += 10 - i;
        }
    }
    return ryan_score - apeach_score;
}
void Com(int idx, int n, vector<int>& info, vector<int>& ryan, vector<int>& best_ryan, int& max_diff)
{
    if (n == 0) {           //만약 화살을 다 썼으면 점수 계산
        int diff = calculateScore(info, ryan);
        if (diff > max_diff) {
            max_diff = diff;
            best_ryan = ryan;
        }
        else if (diff == max_diff) {        //만약 최대 점수가 같다면 점수를 더 많이 맞힌경우를 선택
            for (int i = 10; i >= 0; i--) {
                if (ryan[i] > best_ryan[i]) {
                    best_ryan = ryan;
                    break;
                }
                else if (ryan[i] < best_ryan[i]) {
                    break;
                }
            }
        }
        return;
    }

    if (idx == 11) return;

    // 현재 점수대를 선택하지 않는 경우
    Com(idx + 1, n, info, ryan, best_ryan, max_diff);

    if (n > 0) {
        ryan[idx]++;
        Com(idx, n - 1, info, ryan, best_ryan, max_diff);
        ryan[idx]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0), best_ryan(11, 0);
    int max_diff = -1;
    Com(0, n, info, ryan, best_ryan, max_diff);

    if (max_diff <= 0) {
        return vector<int>{-1};
    }
    return best_ryan;
}