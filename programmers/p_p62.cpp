#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int row = i / n;        //���� �迭���� ũ��� ���� ��
        int col = i % n;        //���� �迭���� ũ��� ���� ������

        answer.push_back(max(row, col) + 1);
    }


    return answer;
}