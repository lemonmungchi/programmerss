#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reserv[25][61];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for (int i = 0; i < book_time.size(); i++) {
        int sh = stoi(book_time[i][0].substr(0, 2));
        int sm = stoi(book_time[i][0].substr(3, 2));
        int fh = stoi(book_time[i][1].substr(0, 2));
        int fm = stoi(book_time[i][1].substr(3, 2));
        fm += 10;

        if (fm > 59) {
            fh++;
            fm -= 60;
        }

        for (int j = sh; j <= fh; j++) {                //���۽ð����� ������ �ð����� �����߰�
            for (int k = 0; k < 60; k++) {
                if (j == sh) {                      //���۽ð��� ������, ���� �۴ٸ� �׳� ����
                    if (k < sm) continue;
                }

                if (j == fh) {
                    if (k >= fm) break;           //������ �ð��϶�, ���� ũ�ų� ���ٸ� break
                }
                reserv[j][k]++;
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 60; j++) {
            answer = max(answer, reserv[i][j]);
        }
    }

    return answer;
}