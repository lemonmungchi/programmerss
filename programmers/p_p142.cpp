#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n, 0);
	vector<int> answer(n, 0);

	stack<int> st;
	st.push(0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		while (!st.empty() && a[st.top()] < a[i]) {
			answer[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) {
		answer[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

}