#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    vector<string> answer(players);


    map<string, int>m;


    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    
    }

    for (int i = 0; i < callings.size(); i++) {
        int locate = m[callings[i]];        //호출된 선수의 등수 가져오기
        m[answer[locate - 1]] += 1;         //등수-1 즉 앞의 선수 등수1증가
        m[callings[i]] -= 1;           //호출된선수 등수-1

        string tmp = answer[locate];        //자기 위치와 그앞선수 바꿔주기
        answer[locate] = answer[locate - 1];
        answer[locate-1] = tmp;
    }

    
    return answer;
}
