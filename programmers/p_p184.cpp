#include <string>
#include <vector>
//순회하면서 자르는 수를 증가시키면서 문자열 비교
using namespace std;
int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {                //i는 문자열을 자르는 길이
        int cnt = 1;                  //겹치는거 숫자
        string tmp = "", a = "";        //압축된 숫자, 자른 숫자
        a = s.substr(0, i);
        for (int j = i; j < s.size(); j += i) {           //자른만큼 순회
            if (a == s.substr(j, i)) cnt++;             //만약 겹치는게 있다면 
            else {
                if (cnt > 1) tmp += to_string(cnt);
                tmp += a;
                a = s.substr(j, i);                //다음에 검사할 부분
                cnt = 1;                  //압축했으면 다시 겹치는거 찾기위해 1로 초기화
            }
        }
        if (cnt > 1) tmp += to_string(cnt);
        tmp += a;
        if (answer > tmp.size())answer = tmp.size();
    }
    return answer;
}