#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// ���ϼ��� �˻��ϴ� �Լ�
bool isUnique(vector<vector<string>>& relation, int columns, int comb) {
    set<string> uniqueCheck;

    // �� Ʃ��(��)�� ���� �˻�
    for (int i = 0; i < relation.size(); i++) {
        string key = "";

        // comb�� �� ��Ʈ�� Ȯ���Ͽ� �ش� ���� �����ϴ��� �˻�
        for (int j = 0; j < columns; j++) {
            if (comb & (1 << j)) {
                // comb�� j��° ��Ʈ�� 1�̸� �ش� ���� key�� �߰�
                key += relation[i][j] + " ";
            }
        }

        // ���ϼ� �˻�: �̹� �����ϴ� Ű��� false ��ȯ
        if (uniqueCheck.find(key) != uniqueCheck.end()) {
            return false;
        }

        // ���ο� Ű�� set�� �߰�
        uniqueCheck.insert(key);
    }

    // ��� Ʃ�ÿ� ���� ���ϼ��� �����ϸ� true ��ȯ
    return true;
}

// �ּҼ��� �˻��ϴ� �Լ�
bool isMinimal(int comb, vector<int>& candidateKeys) {
    // ������ �ĺ�Ű�鿡 ���� �˻�
    for (int key : candidateKeys) {
        // ������ �ĺ�Ű�� ���� ���տ� ���ԵǴ��� �˻�
        if ((comb & key) == key) {
            // ���� �ĺ�Ű�� ���� ������ �κ������̸� �ּҼ� �������� ����
            return false;
        }
    }

    // ��� ���� �ĺ�Ű�� ���� ������ �κ������� �ƴϸ� �ּҼ� ����
    return true;
}

int solution(vector<vector<string>> relation) {
    int rows = relation.size();     // Ʃ��(��)�� ����
    int columns = relation[0].size(); // �Ӽ�(��)�� ����
    vector<int> candidateKeys;     // �ĺ�Ű�� ������ ����

    // ��� ������ �Ӽ� ������ ����
    for (int comb = 1; comb < (1 << columns); comb++) {
        // ���ϼ��� �ּҼ� �˻�
        if (isUnique(relation, columns, comb) && isMinimal(comb, candidateKeys)) {
            // ���ϼ��� �ּҼ��� �����ϴ� ��� �ĺ�Ű�� �߰�
            candidateKeys.push_back(comb);
        }
    }

    // �ĺ�Ű�� ���� ��ȯ
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

    cout << solution(relation) << endl;  // ���: 2
    return 0;
}
