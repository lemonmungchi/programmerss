#include <string>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int min = 0;
    int max = 0;
    vector<string>st1;
    vector<string>st2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);


    for (int i = 0; i < str1.length() - 1; i++) {
        string s1 = str1.substr(i, 2);
        if (s1[0] >= 'a' && s1[0] <= 'z' && s1[1] >= 'a' && s1[1] <= 'z') {
            st1.push_back(s1);
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        string s2 = str2.substr(i, 2);
        if (s2[0] >= 'a' && s2[0] <= 'z' && s2[1] >= 'a' && s2[1] <= 'z') {
            st2.push_back(s2);
        }
    }

    if (st1.empty() && st2.empty()) {
        return 65536;
    }

    max = st1.size() + st2.size();                  //전체집합의 개수의 합

    if (st1.size() > st2.size()) {
        for (int i = 0; i < st2.size(); i++) {
            auto it = find(st1.begin(), st1.end(), st2[i]);
            if (it != st1.end()) {
                min++;
                st1.erase(it);                  //교집합에 찾았다면 그 원소를 제거 
            }
        }
    }
    else {
        for (int i = 0; i < st1.size(); i++) {
            auto it = find(st2.begin(), st2.end(), st1[i]);
            if (it != st2.end()) {
                min++;
                st2.erase(it);              //교집합에 찾았다면 그 원소를 제거 
            }
        }
    }


    max -= min;               //합집합의 개수= 전체집합의개수-교집합의 개수

    if (max == 0) return 65536;

    double a = (double)min / (double)max;


    return a * 65536;
}