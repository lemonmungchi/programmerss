#include <string>
#include <vector>
#include<cmath>
using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int su;
    int mo;
    if (denom1 == denom2) {
        su = numer1 + numer2;
        mo = denom1;
    }
    else {
        su = (numer1 * denom2 + numer2 * denom1);
        mo = denom1 * denom2;
    }
    int i = 2;
    while (i < 1000) {
        if (su % i == 0 && mo % i == 0) {
            su /= i;
            mo /= i;
        }
        else {
            i++;
        }
    }
    answer.push_back(su);
    answer.push_back(mo);
    return answer;
}