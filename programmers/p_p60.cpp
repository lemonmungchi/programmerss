#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> sums;
int solution(vector<int> elements) {
    int answer = 0;
    for (int i = 1; i <= elements.size(); i++) {     // 총길이만큼 반복
        int sum = 0;
        for (int j = i; j < i + elements.size(); j++) {       //현재위치에서 현재위치 제외하고 모든 자리순회
            int idx = j % elements.size();          //다른 모든 자리를 순회할 수 있도록 나머지값으로 반환
            sum += elements[idx];                 //순회하면서 얻은 부분합 저장
            sums.emplace(sum);                  //부분합 중복제외하고 저장할 수있도록 set값으로 저장
        }
    }

    answer = sums.size();
    return answer;
}

//부분 수열의 길이를 1부터 elements.size()까지
//각 원소의 인덱스부터 len 길이 만큼 각 원소의 합을 구해 set에 넣어준다.
//2 - 1. 만약 인덱스가 element.size()를 넘어간다면 원형 수열이기 때문에 % elements.size()를 해준다.
//set의 크기 리턴