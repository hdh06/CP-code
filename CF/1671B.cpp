#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for (auto &x: v) cin >> x;
	int dem = 0;
	for (int i = 1; i < n; i++) dem += v[i] - v[i - 1] - 1;
	if (dem > 2){
		cout << "NO\n";
	}else cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}