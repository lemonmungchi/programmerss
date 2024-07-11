#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//결국은 그리디
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int delivery_load = 0;  // 현재 트럭에 실린 배달 상자 수
    int pickup_load = 0;    // 현재 트럭에 실린 수거 상자 수

    // 가장 먼 집부터 순회
    for (int i = n - 1; i >= 0; --i) {
        // 해당 집에 배달하거나 수거할 상자가 있는 경우에만 작업
        if (deliveries[i] > 0 || pickups[i] > 0) {
            int rounds = 0;  // 해당 집에 대한 왕복 횟수

            // 배달 또는 수거할 상자가 트럭 용량보다 많은 경우 추가로 왕복해야 함
            while (delivery_load < deliveries[i] || pickup_load < pickups[i]) {
                rounds++;
                delivery_load += cap;  // 트럭에 최대 용량만큼 배달 상자를 추가로 실음
                pickup_load += cap;    // 트럭에 최대 용량만큼 수거 상자를 추가로 실음
            }

            // 해당 집에서 배달할 상자를 트럭에서 내림
            delivery_load -= deliveries[i];
            // 해당 집에서 수거할 빈 상자를 트럭에 실음
            pickup_load -= pickups[i];

            // 왕복 거리를 답에 추가 (집까지의 거리 * 2 * 왕복 횟수)
            answer += (i + 1) * 2 * rounds;
        }
    }

    return answer;
}
