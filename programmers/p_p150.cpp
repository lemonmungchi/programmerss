#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnt += k / a[i];
		k %= a[i];
	}

	cout << cnt << "\n";
}