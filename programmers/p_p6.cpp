#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct {
    int x, y;
}pos;
pos moved[4] = { {-1,0},{1,0},{0,-1},{0,1} };
map<char, int>maps = { {'N',0},{'S',1},{'W',2},{'E',3} };

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h = park.size();
    int w = park[0].size();
    answer.push_back(0);
    answer.push_back(0);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (park[i][j] == 'S') {
                answer[0] = i;            //x
                answer[1] = j;            //y
                break;
            }
        }
    }

    for (const auto& route : routes) {
        char dir = maps[route[0]];
        int n = route[2]-48;

        int nx = answer[0];             //x
        int ny = answer[1];             //y

        while (n--) {
            nx += moved[dir].x;
            ny += moved[dir].y;

            if ((nx < 0 || h <= nx || ny < 0 || w <= ny) || park[nx][ny] == 'X')
                break;
        }

        if (n < 0) {
            answer[0] = nx;
            answer[1] = ny;
        }
        
    }

    return answer;
}