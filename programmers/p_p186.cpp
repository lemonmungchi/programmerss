#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> tmp;
    vector<double> sum;
    int n = k;
    int cnt = 0;          //��ڼ����� ����� Ƚ��
    tmp.push_back(n);
    //��ڼ��� ���
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        else {
            n = n * 3 + 1;
            cnt++;
        }
        if (n < 1) {
            break;
        }
        else {
            tmp.push_back(n);
        }
    }
    //������ ���� ���
    for (int i = 0; i < cnt; i++) {
        sum.push_back((tmp[i] + tmp[i + 1]) / 2);
    }
    //������ ���
    for (int i = 0; i < ranges.size(); i++) {
        double tmpsum = 0;
        if (ranges[i][0] <= cnt + ranges[i][1]) {
            for (int j = ranges[i][0]; j < cnt + ranges[i][1]; j++) {
                tmpsum += sum[j];
            }
            answer.push_back(tmpsum);
        }
        else {
            answer.push_back(-1);
        }
    }
    return answer;
}