#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.length(); i++) {         //1�ܰ�
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
    }
    for (int i = 0; i < new_id.length();) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-'
            || new_id[i] == '_' || new_id[i] == '.') {            //2�ܰ�  ������ �׳� �Ѿ��
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }
    for (int i = 0; i < new_id.length();) {            //3�ܰ�
        if (new_id[i] == '.' && new_id[i - 1] == '.') {           //�Ѵ� .. �ϰ�� �տ��� ���� �̶� ī��Ʈ�� �ٱ⶧���� i++
            new_id.erase(new_id.begin() + i);             //�� else������
            continue;
        }
        else {
            i++;
        }
    }
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.end() - 1);        //4�ܰ�

    if (new_id.length() == 0) new_id = "a";          //5�ܰ�

    if (new_id.length() >= 16) {                      //6�ܰ�
        new_id.erase(15, new_id.length() - 1);
    }
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

    if (new_id.length() <= 2) {                      //7�ܰ�
        while (new_id.length() <= 2) {
            new_id += new_id[new_id.length() - 1];
        }
    }


    return new_id;
}
