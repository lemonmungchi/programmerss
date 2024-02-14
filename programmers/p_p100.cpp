#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int answerlen = number.size() - k;         //나오게될 정답길이
    int startidx = 0;
    for (int i = 0; i < answerlen; ++i) {          //정답길이만큼 글자를 가져와야함 
        char maxnum = number[startidx];
        int maxidx = startidx;
        for (int j = startidx; j <= k + i; j++) {         //최대 글자 비교 -> k+i만큼 
            if (maxnum < number[j]) {
                maxnum = number[j];
                maxidx = j;
            }
        }
        startidx = maxidx + 1;          //최대값 지정한거 제외
        answer += maxnum;
    }
    return answer;
}