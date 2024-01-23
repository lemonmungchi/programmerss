#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs_target(vector<int> numbers, int target, int sum, int index) {        //dfs=> 재귀함수로 구현, 종료조건 필요
    //종료조건
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    //재귀함수
    dfs_target(numbers, target, sum + numbers[index], index + 1);             //양수일때
    dfs_target(numbers, target, sum - numbers[index], index + 1);             //음수일때
}

int solution(vector<int> numbers, int target) {

    dfs_target(numbers, target, 0, 0);         //시작값 index,sum 0부터
    return answer;
}