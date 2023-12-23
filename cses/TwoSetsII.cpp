#include <bits/stdc++.h>

using namespace std;

int const W = 500*501/2 + 1;
int const MOD = 1e9 + 7;

int main(){
	int n; cin >> n;

	int dp[W] = {};
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = n*(n + 1)/2; j >= 1; j--)
			if (j - i >= 0) (dp[j] += dp[j - i]) %= MOD;
	
	if (n*(n + 1) % 4 != 0) cout << 0;
	else cout << dp[n*(n + 1)/4]*1LL*500000004 % MOD;
	// 500000004 is modular inverse of 1/2
	return 0;
}