#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum;
    map<string, int>m1;

    for (int i = 0; i < name.size(); i++) {
        m1[name[i]] = yearning[i];
    }
    
    for (int i = 0; i < photo.size(); i++) {
        sum = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            sum += m1[photo[i][j]];
        }
        answer.push_back(sum);
    }

    return answer;
}