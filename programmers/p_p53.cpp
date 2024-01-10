#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    m[words[0]] = 1;
    for (int i = 1; i < words.size(); i++) {
        m[words[i]]++;
        if (words[i - 1].back() != words[i].front()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        else {
            if (m[words[i]] > 1) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                break;
            }
        }

    }
    return answer;
}