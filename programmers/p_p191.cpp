#include <string>
#include <vector>
using namespace std;

int rates[4] = { 40, 30, 20, 10 };  // 할인율
vector<pair<int, int>> price(7, { 0, 0 });  // 할인된 가격, 할인율
vector<int> answer(2, 0);

void dfs(int cnt, int n, vector<vector<int>> users, vector<int> emoticons) {
    if (cnt == n) {  // 모든 이모티콘에 할인율을 대입했을 때 
        int plus = 0, sum = 0;
        for (int i = 0; i < users.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (users[i][0] <= price[j].second) // 원하는 할인율 이상이면 구매
                    tmp += price[j].first;
            if (tmp >= users[i][1]) // 구매값이 정해진 가격 이상이면 이모티콘플러스 가입
                plus++;
            else
                sum += tmp;  //정해진 가격이하라면 이모티콘 구매
        }
        if (plus > answer[0]) {  // 기존 가입자수보다 많으면 
            answer[0] = plus;
            answer[1] = sum;
        }
        else if (plus == answer[0] && sum >= answer[1])
            answer[1] = sum;  // 가입자수가 같고 이윤이 크면
        return;
    }
    for (int i = 0; i < 4; i++) {
        price[cnt].first = (100 - rates[i]) * emoticons[cnt] / 100;  // 할인된 가격
        price[cnt].second = rates[i];  // 할인율
        dfs(cnt + 1, n, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    dfs(0, emoticons.size(), users, emoticons);
    return answer;
}
