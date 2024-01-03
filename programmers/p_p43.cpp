#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    int sum = 0; int len = 1000001;         //최대길이값
    queue<pair<int, int>> q;             //합과 위치를 저장할 큐-> 큐가 빠름

    for (int i = 0; i < sequence.size(); i++) {
        q.push({ sequence[i],i });
        sum += sequence[i];

        while (sum > k) {                   //만약 부분합이 k보다 크다면 제일 앞에 값부터 빼줌
            sum -= q.front().first;
            q.pop();
        }

        if (sum == k && q.size() < len) {                   //k와 같은 부분합을 찾았을때, 초기 길이를 저장 
            len = q.size();                           //만약 그 길이보다 작으면서 부분합이 k에 해당하는 것을 찾았다면 
            answer[0] = q.front().second;             //answer 갱신
            answer[1] = q.back().second;
        }
    }
    return answer;
}