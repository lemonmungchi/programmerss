#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string v = "";                          //ingredient를 string 으로 바꿔서 하나씩 저장한 다음 햄버거 1개의 길이의 기준인 4를 넘으면 뒤의 4개를 짤라서 1231이 맞는지 검사 
    for (auto i : ingredient) {             // 맞다면 answer++ 하고 1231을 뺀 v를 저장
        v += to_string(i);
        if (v.length() >= 4) {
            int idx = v.length() - 4;
            //auto idx = v.find("1231");            //find를 쓰면 시간복잡도가 너무 커짐 -> substr로 젤끝에 4개만 가져와서 1231인지 확인 
            string tmp = v.substr(idx);             
            if (tmp == "1231") {
                v = v.substr(0, idx);
                answer++;
            }
        }
    }
    return answer;
}