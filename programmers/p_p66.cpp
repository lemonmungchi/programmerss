#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> cl;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
        cl[clothes[i][1]]++;
    }
    for (auto i = cl.begin(); i != cl.end(); i++) {
        answer *= i->second + 1;                    //각각의 옷종류의 개수 +1 곱해주면 전체 
    }
    answer--;                                  //아무종류의 옷도 입지않은 경우 제외
    return answer;
}