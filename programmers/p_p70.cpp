#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num;                //방문한 던전 수 체크할 전역 변수
bool visited[9];

int dfs(vector<vector<int>> dungeons, int k, int dcnt) {       //dcnt: 현재 방문한 던전수
    num = max(num, dcnt);                           //나온 dnt값중 최대의 값을 값을 답으로 

    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] || dungeons[i][0] > k) continue;

        visited[i] = 1;                           //방문처리
        dfs(dungeons, k - dungeons[i][1], dcnt + 1);          //방문한 던전의 피로도 뺀값으로 함수 재귀호출
        visited[i] = 0;                       //더 최선의 값이 나올수도 있는 경우의수 고려
    }

    return num;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    answer = dfs(dungeons, k, 0);
    return answer;
}