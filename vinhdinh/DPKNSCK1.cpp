#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;

int main(){
	int n, m;
	cin >> n >> m;

	int v[N], w[N];
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	int dp[N][N] = {};

	int maxn = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (i - w[j] >= 0) dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - w[j]] + v[j]);
			else dp[j][i] = dp[j - 1][i];
		}
		maxn = max(maxn, dp[n][i]);
	}

	cout << maxn;
	return 0;
}