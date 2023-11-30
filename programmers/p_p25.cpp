using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long cost = 0;           //�����÷ο� ����
    for (int i = 1; i <= count; i++) {
        cost += price * i;
    }
    if (cost - money <= 0) {
        answer = 0;
    }
    else if (cost > money) {
        answer = cost - money;
    }
    return answer;
}