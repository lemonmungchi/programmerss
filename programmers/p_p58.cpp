#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ucl(int a, int b) {
    int A = max(a, b);
    int B = min(a, b);

    while (A % B != 0) {

        int R = A % B;
        A = B;
        B = R;
    }
    return B;
}

int solution(vector<int> arr) {         //�ּҰ����=�� ���� ��/�ִ����� �ִ�����= ��Ŭ���� ȣ����
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int UCL = ucl(answer, arr[i]);             //��Ŭ���� ȣ�������� �ִ����� ���ϱ�
        int LCM = answer * arr[i] / UCL;              //�ּҰ����=�� ���� ��/�ִ�����
        answer = LCM;
    }

    return answer;
}