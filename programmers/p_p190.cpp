#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 특정 시작점에서 그룹의 크기를 찾는 함수
int find_group(int start, vector<int>& cards, vector<bool>& visited) {
    int group_size = 0;  // 그룹 크기 초기화
    int current = start;  // 현재 상자를 시작 상자로 설정
    while (!visited[current]) {  // 현재 상자가 방문되지 않은 동안 반복
        visited[current] = true;            //방문처리 
        current = cards[current] - 1;  // 상자 안의 숫자를 통해 다음 상자 선택
        group_size += 1;  // 그룹 크기를 증가시킴
    }
    return group_size;
}

int solution(vector<int> cards) {
    int n = cards.size();  // 상자의 수
    vector<bool> visited(n, false);  // 방문 여부를 저장
    vector<int> group_sizes;  // 각 그룹의 크기를 저장

    // 모든 상자에 대해 그룹을 찾음
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {  // 현재 상자가 방문되지 않았다면
            int group_size = find_group(i, cards, visited);  // 그룹의 크기를 찾음
            group_sizes.push_back(group_size);  // 그룹 크기를 벡터에 추가
        }
    }

    // 그룹 크기를 내림차순으로 정렬
    sort(group_sizes.rbegin(), group_sizes.rend());

    // 최대 점수를 계산
    if (group_sizes.size() < 2) {  // 그룹이 2개 미만이면
        return 0;  // 점수는 0
    }
    else {
        return group_sizes[0] * group_sizes[1];  // 가장 큰 두 그룹의 크기를 곱한 값이 최대 점수
    }
}
