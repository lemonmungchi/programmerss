#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
//닉네임은 맵을 통해 최신화해주기
//나머지는 어떻게 저장해둘것인가..
//->따로 배열을 만들어서 저장하는게 좋겠다=> state배열 answer에는 id만 저장해서 나중에 합쳐주기
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
            state.push_back("님이 들어왔습니다.");
            answer.push_back(id);               //id를 저장해서 나중에 state와 map을 합치기
            m[id] = name;
        }
        else if (status == "Leave") {
            state.push_back("님이 나갔습니다.");
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