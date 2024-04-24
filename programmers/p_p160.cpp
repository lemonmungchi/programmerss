#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for (int i = 0; i < babbling.size(); i++) {
        bool check = false;
        for (int j = 0; j < babbling[i].size(); j++) {
            if (babbling[i].substr(j, 3) == "aya") j += 2;
            else if (babbling[i].substr(j, 2) == "ye") j += 1;
            else if (babbling[i].substr(j, 3) == "woo") j += 2;
            else if (babbling[i].substr(j, 2) == "ma") j += 1;
            else {               //순회했을 때 발음 불가능한 것만 있을 때 
                check = true;
                break;
            }
        }
        if (!check) answer++;            // 순회했을 때 발음가능한 것으로만 단어가 구성되어있을 때 
    }
    return answer;
}