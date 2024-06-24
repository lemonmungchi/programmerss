#include <string>
#include <vector>
#include <cmath>

using namespace std;
//최대점 0,d d,0 안에서 정의되는 점의 개수 
long long solution(int k, int d) {
    long long answer = 0;
    for (long long x = 0; x <= d; x += k) {           //x에 따른 y값 계산
        int maxy = sqrt((long long)d * d - (long long)x * x);       //x값에 따른 y의 최대값 계산
        answer += (maxy / k) + 1;         //y의 최대값에 따른 x의 갯수 계산-> 좌표 개수 
        //+1의 이유: y가 0일때도 포함시키려고
    }
    return answer;
}