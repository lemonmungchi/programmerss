#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

// ������ ������ �����ϱ� ���� �ؽø�
unordered_map<string, vector<int>> info_map;

// ��� ������ ���� ������ �����Ͽ� �ؽøʿ� �����ϴ� �Լ�
void add_info(const vector<string>& info_tokens, int score) {
    string languages[] = { info_tokens[0], "-" };
    string jobs[] = { info_tokens[1], "-" };
    string careers[] = { info_tokens[2], "-" };
    string foods[] = { info_tokens[3], "-" };

    // �� ���Ǻ��� ������ ��� ������ ����
    for (const string& lang : languages) {
        for (const string& job : jobs) {
            for (const string& career : careers) {
                for (const string& food : foods) {
                    string key = lang + job + career + food;
                    info_map[key].push_back(score);  // �ش� ������ Ű�� ���� �߰�
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    // 1. ������ ������ �Ľ��ϰ� info_map�� ����
    for (const string& inf : info) {
        stringstream ss(inf);
        string lang, job, career, food;
        int score;
        ss >> lang >> job >> career >> food >> score;
        vector<string> info_tokens = { lang, job, career, food };
        add_info(info_tokens, score);  // ������ �ؽøʿ� �߰�
    }

    // �� Ű�� ���� ���� ����Ʈ�� �����Ͽ� ���� Ž���� �����ϰ� ��
    for (auto& [key, scores] : info_map) {
        sort(scores.begin(), scores.end());
    }

    vector<int> answer;

    // 2. �� ������ ó��
    for (const string& qry : query) {
        stringstream ss(qry);
        string lang, job, career, food, temp;
        int score;
        ss >> lang >> temp >> job >> temp >> career >> temp >> food >> score;

        string key = lang + job + career + food;  // ������ �ش��ϴ� Ű�� ����
        const vector<int>& scores = info_map[key];  // �ش� Ű�� ����� ���� ����Ʈ�� ������

        // lower_bound�� ����Ͽ� �־��� ���� �̻��� ù ��° ��ġ�� ã��
        auto it = lower_bound(scores.begin(), scores.end(), score);
        // �ش� ��ġ���� �������� ������ ������ �����ϴ� �������� ��
        answer.push_back(scores.end() - it);
    }

    return answer;
}
