#include <bits/stdc++.h>

using namespace std;

int const N = 102;

int main(){
	int n, m; cin >> n >> m;
	int dp[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = INT_MIN;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			cin >> dp[i][j];

	for (int j = 2; j <= m; j++)
		for (int i = 1; i <= n; i++)
			dp[i][j] += max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]});

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i][m]);

	cout << ans;
	return 0;
}