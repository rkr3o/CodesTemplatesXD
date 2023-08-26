//It's just reading the input into the variables.

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a;
	string s;
	getline(cin, s);
	istringstream fin(s);
	int input;
	while(fin >> input) {
		a.push_back(input);
	}
	int n = a.size();
	int k; cin >> k;
	return 0;
}
