#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;       //보조 컨테이너
    for (int i = 1; i <= order.size(); i++) {
        s.push(i);

        while (!s.empty() && s.top() == order[answer]) {          //answer을 인덱스로 => 택배상자에 하나씩 쌓일때마다 order순서 확인
            s.pop();
            answer++;
        }
    }
    return answer;
}