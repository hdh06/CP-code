#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, x; cin >> n >> x;
	bool a = 0, b = 0;
	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		if (t >= x) a = 1;
		if (t <= x) b = 1;
	}
	if (a*b)
		cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}