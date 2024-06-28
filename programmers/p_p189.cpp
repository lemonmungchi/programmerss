#include <string>
#include <vector>
#include <cmath>
using namespace std;
//한 사분면의 값을 찾아서 4배 시켜주기 
long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i <= r2; i++) {
        int maxY = floor(sqrt((long long)r2 * r2 - (long long)i * i));            //최대 Y값 내림해야 경계안쪽의 값까지 구할 수 있다.
        int minY = ceil(sqrt((long long)r1 * r1 - (long long)i * i));             //최소 Y값 올림해야 경계바로 바깥쪽까지의 값을 구할 수 있다.

        if (r1 < i) minY = 0;            //x값이 r1보다 크면 사이이여서 최소y는 0부터 시작

        answer += (maxY - minY + 1);

    }
    return answer * 4;
}