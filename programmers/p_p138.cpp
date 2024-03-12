#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> cnt(1001, 0);      //몸무게 별 사람수
    for (int i = 0; i < weights.size(); i++) {
        cnt[weights[i]]++;
    }
    //나올수 있는 비율 2:3 2:4=1:2 3:4
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] % 2 == 0) {                //2:3
            long long base = (weights[i] / 2) * 3;
            if (base <= 1000) answer += cnt[base];
        }
        if (weights[i] % 3 == 0) {                //3:4
            long long base = (weights[i] / 3) * 4;
            if (base <= 1000) answer += cnt[base];
        }
        long long base = weights[i] * 2;
        if (base <= 1000) answer += cnt[base];
    }

    for (int i = 100; i <= 1000; i++) {
        if (cnt[i] >= 2)
            answer += (long long)(cnt[i] * (cnt[i] - 1)) / 2;           //같을 때
    }

    return answer;
}