#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
//�г����� ���� ���� �ֽ�ȭ���ֱ�
//�������� ��� �����صѰ��ΰ�..
//->���� �迭�� ���� �����ϴ°� ���ڴ�=> state�迭 answer���� id�� �����ؼ� ���߿� �����ֱ�
vector<string> solution(vector<string> record) {
    vector<string> answer, state;
    map<string, string> m;
    stringstream ss;
    for (auto reco : record) {
        ss.str(reco);
        string status, id, name;
        ss >> status >> id >> name;
        ss.clear();
        if (status == "Enter") {
            state.push_back("���� ���Խ��ϴ�.");
            answer.push_back(id);               //id�� �����ؼ� ���߿� state�� map�� ��ġ��
            m[id] = name;
        }
        else if (status == "Leave") {
            state.push_back("���� �������ϴ�.");
            answer.push_back(id);
        }
        else {
            m[id] = name;
        }


    }

    for (int i = 0; i < answer.size(); i++) {
        answer[i] = m[answer[i]] + state[i];
    }
    return answer;
}