#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int r;

    while (storey > 0) {
        r = storey % 10;           //나머지
        storey = storey / 10;      //10으로 나눈 나머지 => 나머지 없애기 자리수 빼기 => 다시 올려줘야함
        if (r > 5 || (r == 5 && storey % 10 >= 5)) {     //5보다 크거나 5랑 같지만 나눈 것을 다시 나눴을때 5보다 크면
            answer += 10 - r;               //5보다 크면 10에서 뺀걸 더하는게 더 나음
            storey++;               //자리수 하나 올리기
        }
        else {              //5보다 작으면 그냥 더하는게 좋음
            answer += r;
        }
    }
    return answer;
}