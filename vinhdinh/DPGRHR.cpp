#include <bits/stdc++.h>

using namespace std;

int const N = 501;

void solve(){
	int n, m; cin >> n >> m;
	int arr[N][N];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	int dp[N][N];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = INT_MAX;

	dp[n][m] = 1;
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--){
			if (i == n && j == m) continue;
			dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - arr[i][j]);
		}
	cout << dp[1][1] << "\n";
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}