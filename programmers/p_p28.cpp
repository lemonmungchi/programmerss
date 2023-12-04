#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int n;
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            cnt++;
        }
        for (int j = 0; j < win_nums.size(); j++) {
            if (win_nums[j] == lottos[i]) {
                cnt2++;
            }
        }
    }
    if (cnt2 >= 2) {
        n = 7;
        n -= cnt2;
    }
    else {
        if (cnt2 == 1) {
            if (cnt >= 1) {              //같은게 하나라도 있을때
                n = 7;
                n -= cnt2;
            }
            else {                   //0 없을때
                n = 6;
            }
        }
        else {           //같은게 하나라도 없을 때
            if (cnt >= 2) {
                n = 6;
                cnt--;
            }
            else {
                n = 6;
            }
        }
    }

    answer.push_back(n - cnt);
    answer.push_back(n);
    return answer;
}