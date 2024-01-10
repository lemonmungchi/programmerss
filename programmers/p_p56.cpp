#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int begin = 0;
    int end = people.size() - 1;
    sort(people.begin(), people.end());
    while (begin <= end) {
        if (people[begin] + people[end] <= limit) {                   //�Ѱ谪���� �۰ų� ������ �ּҰ��� �÷��� �׽�Ʈ
            begin++;
        }
        end--;                                  //�ݺ��Ҷ����� ����Ʈ�� 1�� ���
        answer++;                               //limit���� Ŀ�� ��� / limit���� �۾Ƶ� ���ļ� ���
    }
    return answer;
}