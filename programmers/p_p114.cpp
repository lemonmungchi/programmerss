#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    answer += "�輭���� " + to_string(it - seoul.begin()) + "�� �ִ�";
    return answer;
}