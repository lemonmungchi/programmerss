#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>

using namespace std;
map<string, int> m1;
map<string, set<string>> report_map;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    for (int i = 0; i < id_list.size(); i++) {
        m1[id_list[i]] = i;
    }

    stringstream ss;
    for (auto rep : report) {
        ss.str(rep);
        string first, second;
        ss >> first >> second;
        report_map[second].insert(first);

        ss.clear();

    }
    for (auto it : report_map) { // it.second = set<string>
        if (it.second.size() >= k) { // 어떤 멤버를 신고한 사람이 k명 이상이면
            for (auto set_it : it.second) { // 신고한 사람들의
                int idx = m1[set_it];
                answer[idx]++; // count 증가 (메일 전송)
            }
        }
    }
    return answer;
}
