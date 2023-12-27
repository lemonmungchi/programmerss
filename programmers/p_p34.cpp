#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> se;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            se.insert(numbers[i] + numbers[j]);
        }
    }

    for (auto it = se.begin(); it != se.end(); ++it) {
        answer.push_back(*it);
    }
    return answer;
}