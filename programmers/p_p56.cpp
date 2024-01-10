#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int begin = 0;
    int end = people.size() - 1;
    sort(people.begin(), people.end());
    while (begin <= end) {
        if (people[begin] + people[end] <= limit) {                   //한계값보다 작거나 같으면 최소값을 올려서 테스트
            begin++;
        }
        end--;                                  //반복할때마다 구명보트가 1번 사용
        answer++;                               //limit보다 커도 사용 / limit보다 작아도 합쳐서 사용
    }
    return answer;
}