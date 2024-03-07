#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<string, int> m1 = { {"code",0},{"date",1},{"maximum",2},{"remain",3} };
int idx;
bool compare(const vector<int>& data1, const vector<int>& data2) {
    return data1[idx] < data2[idx];
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    idx = m1[sort_by];
    for (auto d : data) {
        if (d[m1[ext]] <= val_ext) {
            answer.push_back(d);
        }
    }
    sort(answer.begin(), answer.end(), compare);
    return answer;
}