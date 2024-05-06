#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int>m1;
int solution(int a, int b, int c, int d) {
    int answer = 0;
    m1[a]++;
    m1[b]++;
    m1[c]++;
    m1[d]++;

    for (auto it : m1) {
        if (it.second == 4) return 1111 * it.first;
        else if (it.second == 3) {
            for (auto it2 : m1) {
                if (it2.second == 1) return (10 * it.first + it2.first) * (10 * it.first + it2.first);
            }
        }
        else if (it.second == 2) {         //2주사위가 같을 때
            int st = 0;
            for (auto it2 : m1) {
                if (it2.second == 2 && it.first != it2.first) {             //2개씩 같을 때
                    st = it2.first;
                    return (it.first + it2.first) * abs(it.first - it2.first);
                }
                else if (it2.second == 1) {                 //2개는 같고 1개씩은 다를 때
                    st = it2.first;
                    for (auto it3 : m1) {
                        if (it3.second == 1 && it3.first != st) {
                            return st * it3.first;
                        }
                    }
                }
            }
        }
        else {
            answer = min({ a,b,c,d });
        }
    }
    return answer;
}