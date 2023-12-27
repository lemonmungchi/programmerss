#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int pos_l = 10;
    int pos_r = 12;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            pos_r = numbers[i];
        }
        else if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            pos_l = numbers[i];
        }
        else {
            if (numbers[i] == 0) {
                numbers[i] = 11;
            }

            int left = abs(numbers[i] - pos_l) / 3 + abs(numbers[i] - pos_l) % 3;          //상하 좌우 몇번이동 
            int right = abs(numbers[i] - pos_r) / 3 + abs(numbers[i] - pos_r) % 3;

            if (left > right) {
                answer += "R";
                pos_r = numbers[i];
            }
            else if (left < right) {
                answer += "L";
                pos_l = numbers[i];
            }
            else {
                if (hand == "left") {
                    answer += "L";
                    pos_l = numbers[i];
                }
                else {
                    answer += "R";
                    pos_r = numbers[i];
                }
            }
        }
    }
    return answer;
}