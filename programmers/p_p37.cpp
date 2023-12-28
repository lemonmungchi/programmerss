#include <string>
#include <vector>
#include <algorithm>
#include <map>



using namespace std;
map<char, int> so;
string solution(string X, string Y) {
    string answer = "";
    for (auto c : X) {
        so[c]++;                    //X에 해당하는 숫자 방문처리
    }
    for (auto c : Y) {
        if (so[c] != 0) {               //방문처리한 숫자가 존재한다면
            answer += c;              //answer에 추가
            so[c]--;                //방문수 감소
        }
    }
    sort(answer.begin(), answer.end(), greater<char>());
    if (answer == "") {
        return "-1";
    }
    else {
        if (answer[0] == '0') {             //비교할때는 ''으로
            return "0";
        }
    }

    return answer;
}