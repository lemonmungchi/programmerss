#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> dic;
int num = 1;
vector<int> solution(string msg) {
    vector<int> answer;
    //A ~ Z ���� ������ ���
    for (char c = 'A'; c <= 'Z'; c++) {
        string s = "";
        s += c;
        dic[s] = num++;
    }
    //�����߰� ����
    string sum = "";
    for (int i = 0; i < msg.length(); i++) {
        sum += msg[i];
        if (dic[sum] == 0) {            //���� ������ ��ϵ������� �ܾ���
            dic[sum] = num++;
            sum = sum.substr(0, sum.length() - 1);           //��ϵ� �ܾ� ����
            answer.push_back(dic[sum]);
            sum = "";                         //�ٽ� �ʱ�ȭ
            i--;                            //��ϵ� �ܾ���� �ٽ�
        }
    }
    answer.push_back(dic[sum]);             //������ �ܾ�

    return answer;
}