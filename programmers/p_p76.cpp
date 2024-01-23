#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> dic;
int num = 1;
vector<int> solution(string msg) {
    vector<int> answer;
    //A ~ Z 까지 사전에 등록
    for (char c = 'A'; c <= 'Z'; c++) {
        string s = "";
        s += c;
        dic[s] = num++;
    }
    //사전추가 과정
    string sum = "";
    for (int i = 0; i < msg.length(); i++) {
        sum += msg[i];
        if (dic[sum] == 0) {            //만약 사전에 등록되지않은 단어라면
            dic[sum] = num++;
            sum = sum.substr(0, sum.length() - 1);           //등록된 단어 추출
            answer.push_back(dic[sum]);
            sum = "";                         //다시 초기화
            i--;                            //등록된 단어부터 다시
        }
    }
    answer.push_back(dic[sum]);             //마지막 단어

    return answer;
}