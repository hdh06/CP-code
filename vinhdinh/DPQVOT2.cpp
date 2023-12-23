#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef long long ll;

int a[N], b[N];

int main(){
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	ll dp[N] = {};
	
	int pos = 1;
	ll maxx = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		while (a[i] - a[pos] >= k) maxx = max(maxx, dp[pos++]);
		dp[i] = max(dp[i], maxx + b[i]);
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	return 0;
}