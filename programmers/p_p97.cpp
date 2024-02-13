#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {      //�����Լ� �����
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>tmp;
    for (int i = 0; i < numbers.size(); i++) {
        tmp.push_back(to_string(numbers[i]));           //string ���ͷ� ����
    }
    sort(tmp.begin(), tmp.end(), cmp);

    for (int i = 0; i < tmp.size(); i++) answer += tmp[i];

    if (answer[0] == '0') return "0";  //���� ū���� 0�̸� �׳� 0
    return answer;
}