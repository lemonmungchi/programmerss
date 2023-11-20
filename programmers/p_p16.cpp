#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<>());
    for (int i = 0; i < score.size(); i++) {
        if ((i + 1) % m == 0) {
            answer += score[i] * m;
        }
    }


    return answer;
}