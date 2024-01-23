#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs_target(vector<int> numbers, int target, int sum, int index) {        //dfs=> ����Լ��� ����, �������� �ʿ�
    //��������
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    //����Լ�
    dfs_target(numbers, target, sum + numbers[index], index + 1);             //����϶�
    dfs_target(numbers, target, sum - numbers[index], index + 1);             //�����϶�
}

int solution(vector<int> numbers, int target) {

    dfs_target(numbers, target, 0, 0);         //���۰� index,sum 0����
    return answer;
}