#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// 유일성을 검사하는 함수
bool isUnique(vector<vector<string>>& relation, int columns, int comb) {
    set<string> uniqueCheck;

    // 각 튜플(행)에 대해 검사
    for (int i = 0; i < relation.size(); i++) {
        string key = "";

        // comb의 각 비트를 확인하여 해당 열을 포함하는지 검사
        for (int j = 0; j < columns; j++) {
            if (comb & (1 << j)) {
                // comb의 j번째 비트가 1이면 해당 열을 key에 추가
                key += relation[i][j] + " ";
            }
        }

        // 유일성 검사: 이미 존재하는 키라면 false 반환
        if (uniqueCheck.find(key) != uniqueCheck.end()) {
            return false;
        }

        // 새로운 키를 set에 추가
        uniqueCheck.insert(key);
    }

    // 모든 튜플에 대해 유일성을 만족하면 true 반환
    return true;
}

// 최소성을 검사하는 함수
bool isMinimal(int comb, vector<int>& candidateKeys) {
    // 기존의 후보키들에 대해 검사
    for (int key : candidateKeys) {
        // 기존의 후보키가 현재 조합에 포함되는지 검사
        if ((comb & key) == key) {
            // 기존 후보키가 현재 조합의 부분집합이면 최소성 만족하지 않음
            return false;
        }
    }

    // 모든 기존 후보키가 현재 조합의 부분집합이 아니면 최소성 만족
    return true;
}

int solution(vector<vector<string>> relation) {
    int rows = relation.size();     // 튜플(행)의 개수
    int columns = relation[0].size(); // 속성(열)의 개수
    vector<int> candidateKeys;     // 후보키를 저장할 벡터

    // 모든 가능한 속성 조합을 생성
    for (int comb = 1; comb < (1 << columns); comb++) {
        // 유일성과 최소성 검사
        if (isUnique(relation, columns, comb) && isMinimal(comb, candidateKeys)) {
            // 유일성과 최소성을 만족하는 경우 후보키로 추가
            candidateKeys.push_back(comb);
        }
    }

    // 후보키의 개수 반환
    return candidateKeys.size();
}

int main() {
    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };

    cout << solution(relation) << endl;  // 출력: 2
    return 0;
}
