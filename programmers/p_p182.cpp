#include <string>
#include <vector>

using namespace std;
void hanoi(int n, int start, int end, int sub, vector<vector<int>>& answer) {

    vector<int> v;
    if (n == 1) {       //�Ѱ��� ���Ҵٸ� from-> to
        v.push_back(start);
        v.push_back(end);
        answer.push_back(v);
    }
    else {
        //n-1���� from -> sub�� �ű��
        hanoi(n - 1, start, sub, end, answer);

        //from-> to
        v.push_back(start);
        v.push_back(end);
        answer.push_back(v);
        //sub-> to
        hanoi(n - 1, sub, end, start, answer);
    }

    return;
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);

    return answer;
}