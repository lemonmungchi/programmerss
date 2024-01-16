#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> cl;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
        cl[clothes[i][1]]++;
    }
    for (auto i = cl.begin(); i != cl.end(); i++) {
        answer *= i->second + 1;                    //������ �������� ���� +1 �����ָ� ��ü 
    }
    answer--;                                  //�ƹ������� �ʵ� �������� ��� ����
    return answer;
}