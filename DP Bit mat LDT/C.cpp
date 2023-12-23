#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[31][1 << 8];

void solve(){
	int n, m; cin >> n >> m;
	if (n < m) swap(n, m);

	memset(dp, 0, sizeof dp);

	for (int i = 0; i < (1 << m); i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
		for (int m1 = 0; m1 < (1 << m); m1++)
			for (int m2 = 0; m2 < (1 << m); m2++){
				bool flag = 0;
				for (int j = 1; j < m; j++){
					int a = !!(m1 & (1 << j));
					int b = !!(m1 & (1 << (j - 1)));
					int c = !!(m2 & (1 << j));
					int d = !!(m2 & (1 << (j - 1)));
					flag |= (a == b) && (b == c) && (c == d);
				}
				if (flag) continue;
				dp[i][m1] += dp[i - 1][m2];				
			}
	ll ans = 0;
	for (int i = 0; i < (1 << m); i++)
		ans += dp[n][i];
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}