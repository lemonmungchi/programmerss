#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Ư�� ���������� �׷��� ũ�⸦ ã�� �Լ�
int find_group(int start, vector<int>& cards, vector<bool>& visited) {
    int group_size = 0;  // �׷� ũ�� �ʱ�ȭ
    int current = start;  // ���� ���ڸ� ���� ���ڷ� ����
    while (!visited[current]) {  // ���� ���ڰ� �湮���� ���� ���� �ݺ�
        visited[current] = true;            //�湮ó�� 
        current = cards[current] - 1;  // ���� ���� ���ڸ� ���� ���� ���� ����
        group_size += 1;  // �׷� ũ�⸦ ������Ŵ
    }
    return group_size;
}

int solution(vector<int> cards) {
    int n = cards.size();  // ������ ��
    vector<bool> visited(n, false);  // �湮 ���θ� ����
    vector<int> group_sizes;  // �� �׷��� ũ�⸦ ����

    // ��� ���ڿ� ���� �׷��� ã��
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {  // ���� ���ڰ� �湮���� �ʾҴٸ�
            int group_size = find_group(i, cards, visited);  // �׷��� ũ�⸦ ã��
            group_sizes.push_back(group_size);  // �׷� ũ�⸦ ���Ϳ� �߰�
        }
    }

    // �׷� ũ�⸦ ������������ ����
    sort(group_sizes.rbegin(), group_sizes.rend());

    // �ִ� ������ ���
    if (group_sizes.size() < 2) {  // �׷��� 2�� �̸��̸�
        return 0;  // ������ 0
    }
    else {
        return group_sizes[0] * group_sizes[1];  // ���� ū �� �׷��� ũ�⸦ ���� ���� �ִ� ����
    }
}
