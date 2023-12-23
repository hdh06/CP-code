#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s; cin >> s;
	int a = 0, b = 0;
	for (auto x: s){
		a += (x == 'A'), b += (x == 'B');
		if (a < b){
			cout << "NO\n";
			return;
		}
	}
	if (s.back() == 'B')
		cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}