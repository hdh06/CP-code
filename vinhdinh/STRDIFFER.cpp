#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;

	int fre[26] = {};

	for (auto x: s)	fre[x - 'a']++;

	int ans = 0;

	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++) if (fre[i] > 1 && fre[j] == 0)
			fre[i]--, fre[j]++, ans++;
		if (fre[i] > 1){
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}