#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long cal(long long a, long long b, char c) {
    if (c == '-') return a - b;
    else if (c == '+') return a + b;
    return a * b;
}
long long solution(string expression) {
    long long answer = 0;
    vector<long long>nums;          //숫자를 저장할 벡터
    vector<char> operators;         //연산자를 저장할 벡터
    vector<char> oper = { '+','-','*' };
    sort(oper.begin(), oper.end());
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {           //숫자 및 연산자 저장 
        if (isdigit(expression[i])) {
            tmp += expression[i];
        }
        else {
            nums.push_back(stoll(tmp));
            operators.push_back(expression[i]);
            tmp = "";
        }
    }
    nums.push_back(stoll(tmp));

    do {
        vector<long long> nsum(nums);               //합을 저장할 벡터
        vector<char>operTmp(operators);            //저장된 연산자
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < operTmp.size();) {
                if (oper[i] == operTmp[j]) {
                    long long csum = cal(nsum[j], nsum[j + 1], operTmp[j]);
                    nsum.erase(nsum.begin() + j, nsum.begin() + j + 2);      //연산한 두 숫자 제거
                    operTmp.erase(operTmp.begin() + j);              //연산자 삭제
                    nsum.insert(nsum.begin() + j, csum);               //숫자를 제거한 자리에 합 넣어주기
                }
                else {
                    j++;                           //연산자 우선순위가 아닐경우에만 다음 연산자로 넘어가게
                }
            }
        }
        answer = max(answer, abs(nsum[0]));
    } while (next_permutation(oper.begin(), oper.end()));

    return answer;
}