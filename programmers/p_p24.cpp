#include <string>
#include <vector>
#include <map>

using namespace std;
int yt, mt, dt, totalt;
int total;
map<char, int> t_amp;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> tmp;
    for (int i = 0; i < terms.size(); i++) {
        char a = terms[i][0];
        int mo = stoi(string(terms[i].begin() + 1, terms[i].end()));
        t_amp[a] = mo;
    }
    yt = stoi(today.substr(0, 4));
    mt = stoi(today.substr(5, 2));
    dt = stoi(today.substr(8, 2));
    totalt = yt * 12 * 28 + (mt - 1) * 28 + dt;
    for (int i = 0; i < privacies.size(); i++) {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char a = privacies[i].back();
        total = y * 12 * 28 + (m - 1) * 28 + d + (t_amp[a] * 28 - 1);
        tmp.push_back(total);
    }


    for (int i = 0; i < tmp.size(); i++) {
        if (totalt > tmp[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}