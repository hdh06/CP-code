#include <bits/stdc++.h>

using namespace std;

int main(){
	string h[10] = {};
	for (int i = 0; i <= 9; i++){
		cin >> h[i];
	}
	
	int t; cin >> t;
	while (t--){
		string ans = "$";
		string s; cin >> s;
		for (auto x: s){
			x -= '0';
			ans = max(ans, h[x]);
		}
		cout << ans << "\n";
	}
	return 0;
}