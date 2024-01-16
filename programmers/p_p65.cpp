#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> a;
        for (int j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            for (int x = 0; x < arr1[0].size(); x++) {
                sum += arr1[i][x] * arr2[x][j];            //행렬연산
            }
            a.push_back(sum);
        }
        answer.push_back(a);
    }

    return answer;
}