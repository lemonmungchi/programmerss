#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()( int a, int b) {
		int first = abs(a);
		int second = abs(b);
		if (first == second) {
			return a > b;		//b가 우선순위
		}
		else {
			return first > second;		//second가 우선순위
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare> pq;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int rq;
		cin >> rq;

		if (rq == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(rq);
		}
	}

}