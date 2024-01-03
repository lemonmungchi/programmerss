#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long quesum1 = 0, quesum2 = 0;
    queue<int> q1; queue<int> q2;
    for (int i = 0; i < queue1.size(); i++) {
        quesum1 += queue1[i];
        q1.push(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++) {
        quesum2 += queue2[i];
        q2.push(queue2[i]);
    }

    if ((quesum1 + quesum2) % 2 != 0) return -1;

    int n = quesum1 * 3;            //최대연산수= q1->q2 - n 모두 q2->q1- 2n / n+2n = 3n 

    while (n--) {
        if (quesum1 > quesum2) {
            int a = q1.front();
            quesum1 -= a;
            quesum2 += a;
            q2.push(a);
            q1.pop();
        }
        else if (quesum1 < quesum2) {
            int a = q2.front();
            quesum2 -= a;
            quesum1 += a;
            q1.push(a);
            q2.pop();
        }
        else {
            return answer;
        }
        answer++;
    }

    return -1;
}