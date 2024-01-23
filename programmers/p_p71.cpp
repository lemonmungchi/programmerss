#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }

    vector<string> cache;                   //젤앞에 있는게 제일 오래전에 사용된 것
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);     //소문자변환 함수
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) {           //캐시에 존재한다면
            cache.erase(it);
            cache.push_back(city);
            answer++;
        }
        else {                  //캐시에 존재하지않는다면
            if (cache.size() < cacheSize) {    //캐시에 빈자리가 있다면
                cache.push_back(city);
            }
            else {
                cache.erase(cache.begin());
                cache.push_back(city);
            }
            answer += 5;
        }
    }

    return answer;
}