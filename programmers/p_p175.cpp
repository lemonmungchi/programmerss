#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long cal(long long a, long long b, char c) {
    if (c == '-') return a - b;
    else if (c == '+') return a + b;
    return a * b;
}
long long solution(string expression) {
    long long answer = 0;
    vector<long long>nums;          //���ڸ� ������ ����
    vector<char> operators;         //�����ڸ� ������ ����
    vector<char> oper = { '+','-','*' };
    sort(oper.begin(), oper.end());
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {           //���� �� ������ ���� 
        if (isdigit(expression[i])) {
            tmp += expression[i];
        }
        else {
            nums.push_back(stoll(tmp));
            operators.push_back(expression[i]);
            tmp = "";
        }
    }
    nums.push_back(stoll(tmp));

    do {
        vector<long long> nsum(nums);               //���� ������ ����
        vector<char>operTmp(operators);            //����� ������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < operTmp.size();) {
                if (oper[i] == operTmp[j]) {
                    long long csum = cal(nsum[j], nsum[j + 1], operTmp[j]);
                    nsum.erase(nsum.begin() + j, nsum.begin() + j + 2);      //������ �� ���� ����
                    operTmp.erase(operTmp.begin() + j);              //������ ����
                    nsum.insert(nsum.begin() + j, csum);               //���ڸ� ������ �ڸ��� �� �־��ֱ�
                }
                else {
                    j++;                           //������ �켱������ �ƴҰ�쿡�� ���� �����ڷ� �Ѿ��
                }
            }
        }
        answer = max(answer, abs(nsum[0]));
    } while (next_permutation(oper.begin(), oper.end()));

    return answer;
}