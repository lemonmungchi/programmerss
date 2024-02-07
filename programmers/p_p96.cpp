#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& arr, int& zero, int& one, int startRow, int startCol, int n) {
    if (n == 1) {               //1. 더이상 분할 할게 없을 때
        if (arr[startRow][startCol] == 1) one++;
        else zero++;
        return;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[startRow + i][startCol + j];
        }
    }

    if (sum == 0) {     //2. 전체가 0일때
        zero++;
        return;
    }
    else if (sum == n * n) {      //3. 전체가 1일때
        one++;
        return;
    }
    else {                  //4. 다를때
        dfs(arr, zero, one, startRow, startCol, n / 2);
        dfs(arr, zero, one, startRow, startCol + n / 2, n / 2);
        dfs(arr, zero, one, startRow + n / 2, startCol, n / 2);
        dfs(arr, zero, one, startRow + n / 2, startCol + n / 2, n / 2);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    dfs(arr, answer[0], answer[1], 0, 0, arr.size());
    return answer;
}