#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//DP=>�ʱⰪ �������ְ� 2,3��°�� ��� ������ �����غ��� �ȴ�.
//DP=>��� ����� ���� ���� ����ϴ� ��
int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4));     //���� �����ŭ �̸� �ʱ�ȭ���ֱ�

    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];            //�ʱⰪ�� �״�� => DP �ʱⰪ����
    }

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {               //2���� ���迭 ��ȸ
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                if (max < dp[i - 1][k])
                    max = dp[i - 1][k];
            }
            dp[i][j] = land[i][j] + max;        //���迭�� ����ũ���� DP�迭�� �ϳ��ϳ� ���� �ϼ���Ű��
        }
    }

    answer = *max_element(dp.back().begin(), dp.back().end());     //�������࿡ ����ū�� ����
    return answer;
}