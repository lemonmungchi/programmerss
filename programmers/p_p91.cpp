#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct fileName {
    int index;      //tail
    string head;        //head
    int number;         //number
};

vector<fileName> v;

bool cmp(const fileName& f1, const fileName& f2) {       //정렬기준 함수 만들기
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.index < f2.index;
        }
        else {
            return f1.number < f2.number;
        }
    }
    else {
        return f1.head < f2.head;
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;

    for (int i = 0; i < files.size(); i++) {
        vector<int> idx;
        for (int j = 0; j < files[i].size(); j++) {
            if ('0' <= files[i][j] && files[i][j] <= '9') {
                idx.push_back(j);               //숫자가 시작하는 위치->idx[0]
            }
        }
        string head = "";
        for (int j = 0; j < idx[0]; j++) {
            head += tolower(files[i][j]);         //숫자 전까지가 head
        }
        string number = files[i].substr(idx[0], idx.size());

        fileName f;
        f.index = i;
        f.head = head;
        f.number = stoi(number);

        v.push_back(f);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(files[v[i].index]);
    }
    return answer;
}