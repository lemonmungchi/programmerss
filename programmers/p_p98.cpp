#include <string>
#include <vector>
#include <queue>
//1.초를 어떻게 셀것인가 -> 무게가 0인을 자동차를 추가하자 및 초 추가
//2.자동차무게의 합이 다리가 견딜 수 있는 무게보다 크다면? -> 0추가
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    queue<int> que;

    int weightSum = 0;        //자동차 무게합 
    int i = 0;                //인덱스
    while (1) {
        int curWeight = truck_weights[i];
        if (i == truck_weights.size()) {            //마지막 값만 남았을경우 
            time += bridge_length;                //다리길이 만큼 걸림
            break;
        }

        if (que.size() == bridge_length) {          //다리길이 만큼 이동했다면
            weightSum -= que.front();             //다리끝에 있는 자동차의 무게를 빼준다.
            que.pop();
        }
        if (weightSum + curWeight <= weight) {
            weightSum += curWeight;
            que.push(curWeight);
            i++;
        }
        else que.push(0);

        time++;
    }
    return time;
}