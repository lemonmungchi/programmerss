#include <string>
#include <vector>

using namespace std;
//비트를 하나씩 밀어주면서 다른비트가 2개이하인 수 찾고 그 중 제일 작은 수 출력
//홀수 일때, 짝수일때 경우 나눠서 생각
//규칙을 잘 생각해보자 여러개를 시도해보자
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {            //짝수일때
            answer.push_back(numbers[i] + 1);
        }
        else {      //홀수일때 
            long long bit = 1;
            //가장 오른쪽부터 차례로 n개의 연속된 1로 이루어진 비트구하기
            while (true) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2;         //다음비트로
            }
            bit = bit / 2;          //최종비트

            answer.push_back(numbers[i] + bit);           //홀수=> 1 비트 개수 n-> n-1까지의 비트수만큼
        }
    }
    return answer;
}