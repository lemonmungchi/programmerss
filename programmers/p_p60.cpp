#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> sums;
int solution(vector<int> elements) {
    int answer = 0;
    for (int i = 1; i <= elements.size(); i++) {     // �ѱ��̸�ŭ �ݺ�
        int sum = 0;
        for (int j = i; j < i + elements.size(); j++) {       //������ġ���� ������ġ �����ϰ� ��� �ڸ���ȸ
            int idx = j % elements.size();          //�ٸ� ��� �ڸ��� ��ȸ�� �� �ֵ��� ������������ ��ȯ
            sum += elements[idx];                 //��ȸ�ϸ鼭 ���� �κ��� ����
            sums.emplace(sum);                  //�κ��� �ߺ������ϰ� ������ ���ֵ��� set������ ����
        }
    }

    answer = sums.size();
    return answer;
}

//�κ� ������ ���̸� 1���� elements.size()����
//�� ������ �ε������� len ���� ��ŭ �� ������ ���� ���� set�� �־��ش�.
//2 - 1. ���� �ε����� element.size()�� �Ѿ�ٸ� ���� �����̱� ������ % elements.size()�� ���ش�.
//set�� ũ�� ����