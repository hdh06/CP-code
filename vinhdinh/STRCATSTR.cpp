#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	vector<int> p(s.size() + 1, s.size());

	for (int i = s.size() - 3; i >= 0; i--){
		p[i] = p[i + 1];
		if (s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 't')
			p[i] = i + 2;
	}

	long long dem = 0;

	for (int i = 0; i < s.size() - 3 + 1; i++){
		dem += s.size() - p[i];
	}

	cout << dem;
	return 0;
}