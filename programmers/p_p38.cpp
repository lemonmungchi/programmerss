#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> tsum;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> cnt;
    for (int i = 0; i < tangerine.size(); i++) {
        tsum[tangerine[i]]++;
    }
    for (auto m : tsum) {
        cnt.push_back(m.second);                    //�������� ���Ϳ� ���� 
    }
    sort(cnt.rbegin(), cnt.rend());                  //�������� ����
    for (int i = 0; i < cnt.size(); i++) {
        if (k > 0) {
            k -= cnt[i];
            answer++;
        }
        else {
            break;
        }
    }
    return answer;
}