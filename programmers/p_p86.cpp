#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;                   //LIFO�� ���������� ���� ���� �ȿ� ��������.
    int size = prices.size();          //��� size�� �����ϴ� �ͺ��� ��������� �����ϸ� ó���ð�����- ����
    for (int i = 0; i < size; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {       //���� �ְ��� �϶��Ѵٸ�
            answer[s.top()] = i - s.top();                    //�ְ��϶��� �ð���ŭ�� �信 �־���
            s.pop();            //���Ҵ��ε��� ���ÿ��� ����
        }
        s.push(i);
    }

    while (!s.empty()) {       //���� �ְ��� �϶��Ѵٸ�
        answer[s.top()] = size - 1 - s.top();                    //����ð�-��ýð�
        s.pop();            //���Ҵ��ε��� ���ÿ��� ����
    }
    return answer;
}