#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const M = 104;
int const MOD = 1e9 + 7;

int main(){
	int n, m; cin >> n >> m;
	int arr[N] = {};
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i]++;
	}

	int dp[N][M] = {};

	if (arr[1] == 1) for (int i = 2; i <= m + 1; i++) dp[1][i] = 1;
	else dp[1][arr[1]] = 1;

	for (int i = 2; i <= n; i++){
		if (arr[i] != 1)
			dp[i][arr[i]] = ((dp[i - 1][arr[i]] + dp[i - 1][arr[i] - 1])%MOD + dp[i - 1][arr[i] + 1])%MOD;			
		else
			for (int j = 2; j <= m + 1; j++)
				dp[i][j] += ((dp[i - 1][j] + dp[i - 1][j + 1])%MOD + dp[i - 1][j - 1])%MOD;
	}	

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m + 1; j++)
	// 		cout << dp[i][j] << " \n"[j == m + 1];

	int tong = 0;
	for (int i = 2; i <= m + 1; i++) tong += dp[n][i], tong %= MOD;
	cout << tong;
	return 0;
}