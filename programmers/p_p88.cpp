#include <string>
#include <vector>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool check = true;                //��ųƮ�� Ȯ���� ����
    vector<char> v;
    for (int i = 0; i < skill_trees.size(); i++) {
        for (int j = 0; j < skill_trees[i].length(); j++) {
            if (skill.find(skill_trees[i][j]) != string::npos) {        //���� ��ųƮ���� �ִ°Ŷ��
                v.push_back(skill_trees[i][j]);
            }
        }

        for (int k = 0; k < v.size(); k++) {
            if (v[k] != skill[k]) {         //������ �����ʴٸ�
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