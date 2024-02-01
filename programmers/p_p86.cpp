#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;                   //LIFO라 젤마지막에 들어간건 제일 안에 남아있음.
    int size = prices.size();          //계속 size을 연산하는 것보다 상수값으로 저장하면 처리시간감소- 꿀팁
    for (int i = 0; i < size; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {       //만약 주가가 하락한다면
            answer[s.top()] = i - s.top();                    //주가하락한 시간만큼을 답에 넣어줌
            s.pop();            //높았던인덱스 스택에서 제거
        }
        s.push(i);
    }

    while (!s.empty()) {       //만약 주가가 하락한다면
        answer[s.top()] = size - 1 - s.top();                    //종료시간-당시시간
        s.pop();            //높았던인덱스 스택에서 제거
    }
    return answer;
}