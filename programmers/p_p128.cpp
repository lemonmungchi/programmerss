#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s1;
    for (int i = 0; i < nums.size(); i++) {
        s1.insert(nums[i]);
    }
    if (s1.size() < nums.size() / 2) {     //종류의수가 가져갈 수 있는 포켓몬보다 작다면
        answer = s1.size();
    }
    else {
        answer = nums.size() / 2;
    }
    return answer;
}