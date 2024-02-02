#include <string>
#include <vector>
#include <map>
using namespace std;

//초기 아이디어= 왼쪽, 오른쪽 따로 순회하면서 종류의 개수 체크
//=>하나에 다 넣어두고 하나씩 빼자.
int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> left;
    map<int, int> right;
    for (int i = 0; i < topping.size(); i++) {
        if (right.find(topping[i]) != right.end()) {     //이미 존재한다면
            right[topping[i]]++;
        }
        else {                  //존재하지않는다면
            right.insert({ topping[i],1 });
        }
    }

    for (int i = 0; i < topping.size(); i++) {
        if (right.find(topping[i]) != right.end()) {
            right[topping[i]]--;
            if (right[topping[i]] == 0) {
                right.erase(topping[i]);
            }
            if (left.find(topping[i]) == left.end()) {
                left.insert({ topping[i],1 });
            }
            else {
                left[topping[i]]++;
            }
        }

        if (left.size() == right.size()) {
            answer++;
        }
    }
    return answer;
}