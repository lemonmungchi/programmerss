#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int row = i / n;        //행은 배열에서 크기로 나눈 몫
        int col = i % n;        //열은 배열에서 크기로 나눈 나머지

        answer.push_back(max(row, col) + 1);
    }


    return answer;
}