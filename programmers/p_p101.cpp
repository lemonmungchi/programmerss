#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string nums[3]{ "4","1","2" };
    while (n) {
        answer = nums[n % 3] + answer;            //진법계산에서 제일 먼저계산된건 제일뒤에
        if (!(n % 3))          //만약 나머지가 0이 아닐경우 
            n = n / 3 - 1;        //진법계산 계속하기
        else
            n = n / 3;
    }

    return answer;
}