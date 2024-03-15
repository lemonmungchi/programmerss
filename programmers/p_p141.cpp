#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N>>L;
	deque<Node> dq;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;

		while (dq.size() && dq.back().first > now) {
			dq.pop_back();
		}
		dq.push_back(Node(now, i));

		if (dq.front().second <= i - L) {
			dq.pop_front();
		}
		cout << dq.front().first << ' ';
	}
	
	
}