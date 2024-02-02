#include <string>
#include <vector>
#include <map>
using namespace std;

//�ʱ� ���̵��= ����, ������ ���� ��ȸ�ϸ鼭 ������ ���� üũ
//=>�ϳ��� �� �־�ΰ� �ϳ��� ����.
int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> left;
    map<int, int> right;
    for (int i = 0; i < topping.size(); i++) {
        if (right.find(topping[i]) != right.end()) {     //�̹� �����Ѵٸ�
            right[topping[i]]++;
        }
        else {                  //���������ʴ´ٸ�
            right.insert({ topping[i],1 });
        }
    }

    for (int i = 0; i < topping.size(); i++) {
        if (right.find(topping[i]) != right.end()) {
            right[topping[i]]--;
            if (right[topping[i]] == 0) {
                right.erase(topping[i]);
            }
            if (left.find(topping[i]) == left.end()) {
                left.insert({ topping[i],1 });
            }
            else {
                left[topping[i]]++;
            }
        }

        if (left.size() == right.size()) {
            answer++;
        }
    }
    return answer;
}