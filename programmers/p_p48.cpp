#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string a = "";
    int zcount = 0, tcount = 0;

    while (s != "1") {
        tcount++;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                a += s[i];                        //1이면 임시저장소에 저장
            }
            else {
                zcount++;
            }
        }
        int len = a.length();
        a.clear();
        s.clear();
        while (len >= 1) {
            s.insert(0, to_string(len % 2));              //2진수변환
            len /= 2;
        }
    }

    answer.push_back(tcount);
    answer.push_back(zcount);

    return answer;
}