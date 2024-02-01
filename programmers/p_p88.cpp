#include <string>
#include <vector>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool check = true;                //스킬트리 확인할 변수
    vector<char> v;
    for (int i = 0; i < skill_trees.size(); i++) {
        for (int j = 0; j < skill_trees[i].length(); j++) {
            if (skill.find(skill_trees[i][j]) != string::npos) {        //만약 스킬트리에 있는거라면
                v.push_back(skill_trees[i][j]);
            }
        }

        for (int k = 0; k < v.size(); k++) {
            if (v[k] != skill[k]) {         //순서가 같지않다면
                check = false;
                break;
            }
        }

        if (check) answer++;

        check = true;
        v.clear();

    }
    return answer;
}