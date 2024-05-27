#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int>m;     //조합한 메뉴 저장할 맵

void dfs(int idx, string tmp, string order) {
    if (tmp.size() > order.size()) {
        return;
    }
    m[tmp]++;
    for (int i = idx; i < order.size(); i++) {
        dfs(i + 1, tmp + order[i], order);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto order : orders) {             //초기화 파트
        sort(order.begin(), order.end());
        dfs(0, "", order);                //조합할 수 있는 모든 메뉴 저장
    }
    for (auto cours : course) {            //검사파트
        int mostOrdered = 0;
        for (auto menu : m) {
            if (menu.first.size() == cours) {       //코스의 개수를 만족하면서 가장 많이 선택된 횟수 선택
                mostOrdered = max(mostOrdered, menu.second);
            }
        }
        if (mostOrdered <= 1)continue;
        for (auto menu : m) {
            if (menu.first.size() == cours && menu.second == mostOrdered) {
                answer.push_back(menu.first);           //조건에 부합한다면 저장
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}