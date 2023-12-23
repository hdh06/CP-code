#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	if (n < m){
		cout << "NO\n";
		return;
	}

	if (a.substr(n - m + 1, m - 1) != b.substr(1, m - 1)){
		cout << "NO\n";
		return;
	}
	for (int i = n - m; i >= 0; i--)
		if (a[i] == b[0]){
			cout << "YES\n";
			return;
		}	
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}