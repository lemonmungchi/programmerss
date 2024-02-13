#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {      //정렬함수 만들기
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>tmp;
    for (int i = 0; i < numbers.size(); i++) {
        tmp.push_back(to_string(numbers[i]));           //string 벡터로 저장
    }
    sort(tmp.begin(), tmp.end(), cmp);

    for (int i = 0; i < tmp.size(); i++) answer += tmp[i];

    if (answer[0] == '0') return "0";  //제일 큰수가 0이면 그냥 0
    return answer;
}