#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	
	int fre[3] = {};
	for (auto x: s) fre[x - '0']++;

	reverse(s.begin(), s.end());

	for (auto &x: s){
		for (int i = 2; i >= 0; i--) if (x - '0' != i){
			if (fre[x - '0'] > n/3)
				if (fre[i] < n/3){
					fre[x - '0'] --;
					fre[i]++;
					x = i + '0';
					break;
				}
		}
	}

	reverse(s.begin(), s.end());

	cout << s;
	return 0;
}