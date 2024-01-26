#include <string>
#include <vector>

using namespace std;
bool visited[201] = { 0 };
void dfs(int n, vector<vector<int>> computers, int cur) {     //연결된함수 모두 방문처리 => 재귀함수로
    visited[cur] = true;
    //재귀함수
    for (int i = 0; i < n; i++) {               //연결된 함수 찾으려고 전체 순회
        if (!visited[i] && computers[cur][i] == 1) {          //연결되고 방문x일때
            dfs(n, computers, i);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //연결된 네트워크를 확인해야함. => dfs 로 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, computers, i);
            answer++;
        }
    }
    return answer;
}