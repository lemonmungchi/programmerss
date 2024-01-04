#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "", token = "";
    vector<int> v;
    int min = 0, max = 0;

    for (stringstream str(s); str >> token;)            //token을 기준으로 문자열 나누기
        v.push_back(stoi(token));
    sort(v.begin(), v.end());

    answer += to_string(v.front()) + ' ' + to_string(v.back());

    return answer;
}