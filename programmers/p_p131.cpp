#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) return a.second < b.second;            //실패율 같다면 숫자 큰 순으로
    else return a.first > b.first;
}

int cnt[501];            //스테이지별 클리어하지 못한 사용자 수
vector<pair<double, int>> failure;           //스테이별 실패율 저장할 벡터
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int st = stages.size();
    for (int i = 0; i < st; i++) {
        cnt[stages[i]]++;           //스테이지별 클리어하지 못한 사용자 수 저장
    }
    int tmp = st;
    for (int i = 1; i <= N; i++) {

        if (cnt[i] == 0) failure.push_back({ 0,i });     //실패한 사람이 없다면 실패율은 0
        else {
            double t = (double)cnt[i] / tmp;             //실패율 계산

            failure.push_back({ t,i });
        }

        tmp -= cnt[i];         //해당단계에서 실패했다면 다음단계도 실패 총 인원 줄이기
    }
    sort(failure.begin(), failure.end(), compare);

    int fsize = failure.size();

    for (int i = 0; i < fsize; i++) {
        auto p = failure[i];
        answer.push_back(p.second);
    }

    return answer;
}