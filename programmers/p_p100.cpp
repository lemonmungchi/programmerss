#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int answerlen = number.size() - k;         //�����Ե� �������
    int startidx = 0;
    for (int i = 0; i < answerlen; ++i) {          //������̸�ŭ ���ڸ� �����;��� 
        char maxnum = number[startidx];
        int maxidx = startidx;
        for (int j = startidx; j <= k + i; j++) {         //�ִ� ���� �� -> k+i��ŭ 
            if (maxnum < number[j]) {
                maxnum = number[j];
                maxidx = j;
            }
        }
        startidx = maxidx + 1;          //�ִ밪 �����Ѱ� ����
        answer += maxnum;
    }
    return answer;
}