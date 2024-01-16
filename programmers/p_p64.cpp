#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {              //최대 h 값은 인용수가 인덱스 수보다 크거나 같아질때 
            answer = i + 1;
        }
    }
    return answer;
}