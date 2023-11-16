#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    int m;
    for (int i = 0; i < score.size(); i++) {
        temp.push_back(score[i]);
        if (i < k) {
            int m = *min_element(temp.begin(), temp.end());
            answer.push_back(m);
        }
        else {
            sort(temp.begin(), temp.end());
            int size = temp.size();
            answer.push_back(temp[size - k]);
        }
    }
    return answer;
}