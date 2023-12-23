#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];	

	vector<int> b(200000, -1);
	for (int i = 1; i <= m; i++){
		int t; cin >> t;
		b[t] = i;
	}

	vector<int> f(200000, INT_MAX);
	f[0] = INT_MIN;

	int ans = 0;

	for (int i = 1; i <= n; i++){
		if (b[a[i]] == -1) continue;
		int k = lower_bound(f.begin(), f.end(), b[a[i]]) - f.begin();
		f[k] = b[a[i]];
		// cout << b[a[i]] << " " << k << "\n";
		ans = max(ans, k);
	}

	cout << ans;
	return 0;
}