#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string nums[3]{ "4","1","2" };
    while (n) {
        answer = nums[n % 3] + answer;            //������꿡�� ���� �������Ȱ� ���ϵڿ�
        if (!(n % 3))          //���� �������� 0�� �ƴҰ�� 
            n = n / 3 - 1;        //������� ����ϱ�
        else
            n = n / 3;
    }

    return answer;
}