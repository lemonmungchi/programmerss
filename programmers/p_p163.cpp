#include <string>
#include <vector>

using namespace std;
int line[200];
int solution(vector<vector<int>> lines) {
    int answer = 0;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = lines[i][0]; j < lines[i][1]; j++) {               //시작점 ~ 도착점-1 까지에 있는 선분있다면 ++
            line[j + 100]++;                  //음수값도 양수값범위안에 들도록
        }
    }
    for (int i = 0; i < 200; i++) {
        if (line[i] >= 2) {
            answer++;
        }
    }
    return answer;
}