#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> visited(1000000, 0);                  //연산수 넣을 벡터 0으로 초기화
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();                  //제일 앞에꺼- 현재위치 꺼내오기
        q.pop();
        if (cur == y) return visited[cur];     //y랑 같아지면 연산 수 가져오기
        int dir[3] = { cur + n,cur * 2,cur * 3 };
        for (int i = 0; i < 3; i++) {
            int nx = dir[i];
            if (nx > y || visited[nx] != 0) continue;      //y보다 크거나 이미 계산한거라면 스킵
            visited[nx] = visited[cur] + 1;
            q.push(nx);
        }
    }

    return -1;
}