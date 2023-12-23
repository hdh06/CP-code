#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int fre[26] = {};

	for (int i = 0; i < n; i++) fre[s[i] - 'A']++;

	int minn = INT_MAX;
	for (int i = 0; i < k; i++){
		minn = min(fre[i], minn);
	}

	cout << minn*k;
	return 0;
}