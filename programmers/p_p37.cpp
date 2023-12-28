#include <string>
#include <vector>
#include <algorithm>
#include <map>



using namespace std;
map<char, int> so;
string solution(string X, string Y) {
    string answer = "";
    for (auto c : X) {
        so[c]++;                    //X�� �ش��ϴ� ���� �湮ó��
    }
    for (auto c : Y) {
        if (so[c] != 0) {               //�湮ó���� ���ڰ� �����Ѵٸ�
            answer += c;              //answer�� �߰�
            so[c]--;                //�湮�� ����
        }
    }
    sort(answer.begin(), answer.end(), greater<char>());
    if (answer == "") {
        return "-1";
    }
    else {
        if (answer[0] == '0') {             //���Ҷ��� ''����
            return "0";
        }
    }

    return answer;
}