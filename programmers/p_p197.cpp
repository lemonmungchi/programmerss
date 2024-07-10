#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

// 지원자 정보를 저장하기 위한 해시맵
unordered_map<string, vector<int>> info_map;

// 모든 가능한 조건 조합을 생성하여 해시맵에 저장하는 함수
void add_info(const vector<string>& info_tokens, int score) {
    string languages[] = { info_tokens[0], "-" };
    string jobs[] = { info_tokens[1], "-" };
    string careers[] = { info_tokens[2], "-" };
    string foods[] = { info_tokens[3], "-" };

    // 각 조건별로 가능한 모든 조합을 생성
    for (const string& lang : languages) {
        for (const string& job : jobs) {
            for (const string& career : careers) {
                for (const string& food : foods) {
                    string key = lang + job + career + food;
                    info_map[key].push_back(score);  // 해당 조합의 키에 점수 추가
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    // 1. 지원자 정보를 파싱하고 info_map에 저장
    for (const string& inf : info) {
        stringstream ss(inf);
        string lang, job, career, food;
        int score;
        ss >> lang >> job >> career >> food >> score;
        vector<string> info_tokens = { lang, job, career, food };
        add_info(info_tokens, score);  // 정보를 해시맵에 추가
    }

    // 각 키에 대해 점수 리스트를 정렬하여 이진 탐색을 가능하게 함
    for (auto& [key, scores] : info_map) {
        sort(scores.begin(), scores.end());
    }

    vector<int> answer;

    // 2. 각 쿼리를 처리
    for (const string& qry : query) {
        stringstream ss(qry);
        string lang, job, career, food, temp;
        int score;
        ss >> lang >> temp >> job >> temp >> career >> temp >> food >> score;

        string key = lang + job + career + food;  // 쿼리에 해당하는 키를 생성
        const vector<int>& scores = info_map[key];  // 해당 키에 저장된 점수 리스트를 가져옴

        // lower_bound를 사용하여 주어진 점수 이상인 첫 번째 위치를 찾음
        auto it = lower_bound(scores.begin(), scores.end(), score);
        // 해당 위치부터 끝까지의 개수가 조건을 만족하는 지원자의 수
        answer.push_back(scores.end() - it);
    }

    return answer;
}
