#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cmpnum;
bool cmp(vector<int> a, vector<int> b) {
    if (a[cmpnum] == b[cmpnum]) {      //만약 col번째 열의 값이 같다면
        // 기본키 (첫 번째 열) 기준 내림차순 정렬
        return a[0] > b[0];
    }

    return a[cmpnum] < b[cmpnum]; //아니라면 
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    cmpnum = col - 1;           //col번째 열
    sort(data.begin(), data.end(), cmp);          //오름차순 정렬

    for (int i = row_begin - 1; i < row_end; i++) {
        int sum = 0;
        for (int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        answer ^= sum;               //각각의 합을 계속 xor해주기
    }

    return answer;
}