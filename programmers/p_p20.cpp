#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int maxh = -1;
    int maxw = -1;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][1] > sizes[i][0]) swap(sizes[i][0], sizes[i][1]);
        if (sizes[i][0] > maxw) maxw = sizes[i][0];
        if (sizes[i][1] > maxh) maxh = sizes[i][1];
    }
    answer = maxh * maxw;
    return answer;
}