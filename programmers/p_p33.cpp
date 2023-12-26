#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.length(); i++) {         //1단계
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
    }
    for (int i = 0; i < new_id.length();) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-'
            || new_id[i] == '_' || new_id[i] == '.') {            //2단계  맞으면 그냥 넘어가기
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }
    for (int i = 0; i < new_id.length();) {            //3단계
        if (new_id[i] == '.' && new_id[i - 1] == '.') {           //둘다 .. 일경우 앞에꺼 삭제 이때 카운트가 줄기때문에 i++
            new_id.erase(new_id.begin() + i);             //는 else문에만
            continue;
        }
        else {
            i++;
        }
    }
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.end() - 1);        //4단계

    if (new_id.length() == 0) new_id = "a";          //5단계

    if (new_id.length() >= 16) {                      //6단계
        new_id.erase(15, new_id.length() - 1);
    }
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

    if (new_id.length() <= 2) {                      //7단계
        while (new_id.length() <= 2) {
            new_id += new_id[new_id.length() - 1];
        }
    }


    return new_id;
}
