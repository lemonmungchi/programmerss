#include <string>
#include <vector>

using namespace std;
//��Ʈ�� �ϳ��� �о��ָ鼭 �ٸ���Ʈ�� 2�������� �� ã�� �� �� ���� ���� �� ���
//Ȧ�� �϶�, ¦���϶� ��� ������ ����
//��Ģ�� �� �����غ��� �������� �õ��غ���
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {            //¦���϶�
            answer.push_back(numbers[i] + 1);
        }
        else {      //Ȧ���϶� 
            long long bit = 1;
            //���� �����ʺ��� ���ʷ� n���� ���ӵ� 1�� �̷���� ��Ʈ���ϱ�
            while (true) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2;         //������Ʈ��
            }
            bit = bit / 2;          //������Ʈ

            answer.push_back(numbers[i] + bit);           //Ȧ��=> 1 ��Ʈ ���� n-> n-1������ ��Ʈ����ŭ
        }
    }
    return answer;
}