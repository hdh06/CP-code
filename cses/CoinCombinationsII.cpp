#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const X = 1e6 + 1;
int const MOD = 1e9 + 7;

int main(){
	int n; cin >> n;
	int x; cin >> x;

	int coins[N];
	for (int i = 1; i <= n; i++) cin >> coins[i];

	int dp[N][X] = {};
	dp[0][0] = 1; 

	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= x; j++){
			dp[i][j] += dp[i - 1][j]; dp[i][j] %= MOD;
			if (j - coins[i] >= 0) dp[i][j] += dp[i][j - coins[i]]; dp[i][j] %= MOD;
		}
	}

	cout << dp[n][x];
	return 0;
}