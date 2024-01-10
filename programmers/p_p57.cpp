#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (a % 2 == 1) a++;            //홀수번째는 나누고 1을 더해줘야 함
        if (b % 2 == 1) b++;

        a /= 2;                        
        b /= 2;
        if (a == b) break;              //나눴을때 같아지면 같은조에 있는거임
    }
    return i;
}