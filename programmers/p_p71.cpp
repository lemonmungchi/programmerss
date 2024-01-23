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

    vector<string> cache;                   //���տ� �ִ°� ���� �������� ���� ��
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);     //�ҹ��ں�ȯ �Լ�
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) {           //ĳ�ÿ� �����Ѵٸ�
            cache.erase(it);
            cache.push_back(city);
            answer++;
        }
        else {                  //ĳ�ÿ� ���������ʴ´ٸ�
            if (cache.size() < cacheSize) {    //ĳ�ÿ� ���ڸ��� �ִٸ�
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