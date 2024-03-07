#include <string>
#include <vector>
#include <map>

using namespace std;
map<int, int> attack;
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int time = attacks[attacks.size() - 1][0];
    int count = 0;
    answer = health;
    for (int i = 0; i < attacks.size(); i++) {
        attack[attacks[i][0]] = attacks[i][1];
    }
    for (int i = 1; i <= time; i++) {
        if (attack[i] != 0) {
            answer -= attack[i];
            count = 0;
            if (answer <= 0) return -1;
        }
        else {
            if (count < bandage[0] && answer <= health) {
                answer += bandage[1];
                count++;
                if (count >= bandage[0]) {
                    answer += bandage[2];
                    count = 0;

                }
            }

        }
        if (health < answer) {
            answer = health;
        }
    }
    return answer;
}