#include <string>
#include <vector>
#include <queue>
//1.�ʸ� ��� �����ΰ� -> ���԰� 0���� �ڵ����� �߰����� �� �� �߰�
//2.�ڵ��������� ���� �ٸ��� �ߵ� �� �ִ� ���Ժ��� ũ�ٸ�? -> 0�߰�
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    queue<int> que;

    int weightSum = 0;        //�ڵ��� ������ 
    int i = 0;                //�ε���
    while (1) {
        int curWeight = truck_weights[i];
        if (i == truck_weights.size()) {            //������ ���� ��������� 
            time += bridge_length;                //�ٸ����� ��ŭ �ɸ�
            break;
        }

        if (que.size() == bridge_length) {          //�ٸ����� ��ŭ �̵��ߴٸ�
            weightSum -= que.front();             //�ٸ����� �ִ� �ڵ����� ���Ը� ���ش�.
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