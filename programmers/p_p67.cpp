#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {                //���̳��¼����� �տ��� ��ġ
    unordered_map<int, int> m1;

    for (int i = 2; i < s.length(); i++) {
        if (isdigit(s[i])) {              //���ڶ��
            m1[stoi(s.substr(i))]++;               //�ش�κ� ++
            while (isdigit(s[i]))                   //������ �κа��
                i++;
        }
    }

    int size = m1.size();
    vector<int> answer(size);               //���� ����ŭ �ʱ�ȭ
    for (auto num : m1) {
        answer[size - num.second] = num.first;          //��ü ���� ����- �ڽ��� ���� ���� �� => �ε���
    }
    return answer;
}