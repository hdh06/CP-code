#include <bits/stdc++.h>

using namespace std;

#define int long long

int md(int bal, int x, int target){
	if (bal >= target) return 0;
	target -= bal;
	return target / x + (target % x != 0);
}

void solve(){
	int n, c; cin >> n >> c;
	vector<int> a(n + 1), b(n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];

	int bal = 0, days = 0;
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++){
		ans = min(ans, days + md(bal, a[i], c));
		days += md(bal, a[i], b[i]) + 1;
		bal += md(bal, a[i], b[i]) * a[i] - b[i];
	}
	cout << ans << "\n";
}	

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}