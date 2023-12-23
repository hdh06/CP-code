#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 10;

int main(){
	int n, m;
	cin >> n >> m;

	int a[N] = {}, b[N] = {};
	int dp[N][N] = {};

	for (int i = 2; i <= n + 1; i++) cin >> a[i];
	for (int j = 2; j <= m + 1; j++) cin >> b[j];

	for (int i = 2; i <= n + 1; i++){
		for (int j = 2; j <= m + 1; j++){
			if (a[i] == b[j]) dp[i][j] = dp[i - 2][j - 2] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			// cout << dp[i][j] << " \n"[j == m];
		}
	}

	cout << dp[n + 1][m + 1];
	return 0;
}