#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//DP=>초기값 설정해주고 2,3번째를 어떻게 구할지 생각해보면 된다.
//DP=>모든 경우의 수를 만들어서 사용하는 것
int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4));     //땅의 사이즈만큼 미리 초기화해주기

    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];            //초기값은 그대로 => DP 초기값설정
    }

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {               //2차원 땅배열 순회
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                if (max < dp[i - 1][k])
                    max = dp[i - 1][k];
            }
            dp[i][j] = land[i][j] + max;        //땅배열과 같은크기의 DP배열을 하나하나 값을 완성시키기
        }
    }

    answer = *max_element(dp.back().begin(), dp.back().end());     //마지막행에 제일큰게 정답
    return answer;
}