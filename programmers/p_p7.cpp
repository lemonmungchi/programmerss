#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                if (answer.size() == 0) {
                    answer.push_back(i);            //置社x
                    answer.push_back(j);            //置社y
                    answer.push_back(i+1);            //置企x
                    answer.push_back(j+1);            //置企y
                }
                else {
                    if (answer[0] > i) {
                        answer[0] = i;
                    }
                    if (answer[2] < i+1) {
                        answer[2] = i+1;
                    }
                    if (answer[1] > j) {
                        answer[1] = j;
                    }
                    if (answer[3] < j+1) {
                        answer[3] = j+1;
                    }
                }
               
  
            }
        }
    }
    return answer;
}