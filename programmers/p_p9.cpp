#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int a;
	int b;

	cin >> a;
	cin >> b;

	string a1 = "";
	a1 += to_string(a);
	a1 += to_string(b);
	int c = stoi(a1);
	cout << a1;
}