#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int main(){
	int n, m; cin >> n >> m;
	int arr[N][N];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	int dp[N][N][N] = {};
	for (int i = 1; i <= n; i++)
		for (int j1 = 1; j1 <= m; j1++)
			for (int j2 = 1; j2 <= m; j2++)
				dp[i][j1][j2] = arr[i][j1] + arr[i][j2]*(j1 != j2) + max({
						dp[i - 1][j1 - 1][j2 - 1],
						dp[i - 1][j1 - 1][j2],
						dp[i - 1][j1 - 1][j2 + 1],

						dp[i - 1][j1][j2 - 1],
						dp[i - 1][j1][j2],
						dp[i - 1][j1][j2 + 1],

						dp[i - 1][j1 + 1][j2 - 1],
						dp[i - 1][j1 + 1][j2],
						dp[i - 1][j1 + 1][j2 + 1],
					});
	
	

	int ans = 0;

	for (int j1 = 1; j1 <= m; j1++)
			for (int j2 = 1; j2 <= m; j2++)
				ans = max(ans, dp[n][j1][j2]);
	cout << ans;
	return 0;
}