#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s, t; cin >> s >> t;
	bool fre[256] = {};
	for (auto x: s) fre[x] = true;
	for (auto x: t) if (fre[x]){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}	
	return 0;
}