#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 41;

ll dp[N][5];
ll dq(int n, int k){
	if (n == 0) return 1;
	if (k == 0 && n > 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];

	return dp[n][k] = dq(n - 1, k) + dq(n, k - 1);
}

void solve(){
	ll n; cin >> n;

	memset(dp, -1, sizeof dp);

	ll ans = 1;
	for (int i = 2; i <= sqrt(n); i++){
		int dem = 0;
		while (n % i == 0) n /= i, dem++;
		ans *= dq(dem, 4);
	}
	if (n > 1) ans *= dq(1, 4);
	cout << ans << "\n";
}

int main(){
	freopen("fourking.inp", "r", stdin);
	freopen("fourking.out", "w", stdout);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}