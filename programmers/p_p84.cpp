#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;
int diff_time(string start, string end) {
    int h1 = stoi(start.substr(0, 2));
    int m1 = stoi(start.substr(3, 2));
    int h2 = stoi(end.substr(0, 2));
    int m2 = stoi(end.substr(3, 2));

    int diff = (h2 - h1) * 60 + (m2 - m1);

    return diff;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> parks;

    stringstream ss;                    //빈칸을 경계로 string 나눔
    for (auto record : records) {
        ss.str(record);             //records에서 record string 형태로 가져오기
        string time, number, status;  //record string에서 나눠줄 변수들 
        ss >> time >> number >> status;

        parks[number].push_back(time);
        ss.clear();
    }

    for (auto it : parks) {
        if (it.second.size() & 1) {         //주차내역 개수가 홀수 일때
            it.second.push_back("23:59");
        }

        vector<string>info = it.second;
        int total = 0;
        for (int i = 0; i < info.size() - 1; i += 2) {
            total += diff_time(info[i], info[i + 1]);
        }

        int price = fees[1];
        if (total > fees[0]) {
            price += ceil((total - fees[0]) / (double)fees[2]) * fees[3];
        }
        answer.push_back(price);
    }

    return answer;
}