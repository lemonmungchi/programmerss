#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<string> split(string input, char del);
int mySum(string a);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	string ex;
	cin >> ex;
	vector<string> s = split(ex, '-');

	for (int i = 0; i < s.size(); i++) {
		int tmp = mySum(s[i]);
		if (i == 0) {				//젤 앞에꺼면 더하고
			answer += tmp;
		}
		else {					//아니면 빼주기 
			answer -= tmp;
		}
	}

	cout << answer << "\n";
}

vector<string> split(string input, char del) {
	vector<string> result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, del)) {		//split
		result.push_back(splitdata);
	}
	return result;
}

int mySum(string a) {			//-하기 전 더하기
	int sum = 0;
	vector<string> tmp = split(a, '+');

	for (int i = 0; i < tmp.size(); i++) {
		sum += stoi(tmp[i]);
	}
	return sum;
}
