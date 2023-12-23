#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int const MOD = 1e9 + 7;

int dp[N][2];

void init(){
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < N; i++){
		(dp[i][0] = 1LL * dp[i - 1][0] * 2 % MOD + dp[i - 1][1]) %= MOD;
		(dp[i][1] = 1LL * dp[i - 1][1] * 4 % MOD + dp[i - 1][0]) %= MOD;
	}
}

int main(){
	init();
	int t; cin >> t;
	while(t--){
		int x;
		cin >> x;
		cout << (dp[x][0] + dp[x][1]) % MOD << "\n";
	}
	return 0;
}