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

int solution(vector<int> arr) {         //최소공배수=두 수의 곱/최대공약수 최대공약수= 유클리드 호제법
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int UCL = ucl(answer, arr[i]);             //유클리드 호제법으로 최대공약수 구하기
        int LCM = answer * arr[i] / UCL;              //최소공배수=두 수의 곱/최대공약수
        answer = LCM;
    }

    return answer;
}