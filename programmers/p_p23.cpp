#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string v = "";                          //ingredient�� string ���� �ٲ㼭 �ϳ��� ������ ���� �ܹ��� 1���� ������ ������ 4�� ������ ���� 4���� ©�� 1231�� �´��� �˻� 
    for (auto i : ingredient) {             // �´ٸ� answer++ �ϰ� 1231�� �� v�� ����
        v += to_string(i);
        if (v.length() >= 4) {
            int idx = v.length() - 4;
            //auto idx = v.find("1231");            //find�� ���� �ð����⵵�� �ʹ� Ŀ�� -> substr�� ������ 4���� �����ͼ� 1231���� Ȯ�� 
            string tmp = v.substr(idx);             
            if (tmp == "1231") {
                v = v.substr(0, idx);
                answer++;
            }
        }
    }
    return answer;
}