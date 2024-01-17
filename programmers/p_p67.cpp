#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {                //많이나온순으로 앞에다 배치
    unordered_map<int, int> m1;

    for (int i = 2; i < s.length(); i++) {
        if (isdigit(s[i])) {              //숫자라면
            m1[stoi(s.substr(i))]++;               //해당부분 ++
            while (isdigit(s[i]))                   //숫자인 부분계산
                i++;
        }
    }

    int size = m1.size();
    vector<int> answer(size);               //나온 수만큼 초기화
    for (auto num : m1) {
        answer[size - num.second] = num.first;          //전체 수의 숫자- 자신이 나온 수의 빈도 => 인덱스
    }
    return answer;
}