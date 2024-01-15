#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int>m1;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i < want.size(); i++) {
        m1[want[i]] = number[i];
    }
    for (int i = 0; i < discount.size(); i++) {                //���� �ϳ��� �˻�
        map<string, int>m2;
        for (int j = i; j < i + 10; j++) {                     //������������ 10�ϱ��� �˻�
            m2[discount[j]] += 1;
            if (j == discount.size() - 1) break;
        }
        if (m2 == m1) answer++;                             //map �ΰ��� ������ -> �ΰ��� ���� ������
    }
    return answer;
}