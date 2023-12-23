#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const N = 201;

int n, a, b; 
int dp[N][N][N] = {};

int dq(int i = 1, int ma = 0, int mb = 0){
	if (i == n + 1){
		if (ma == 0 && mb == 0) return 1;
		return 0;
	}

	if (dp[i][ma][mb] != -1) return dp[i][ma][mb];

	int ans = 0;
	for (int d = 0; d <= 9; d++){
		int next_ma = (ma + (d % a)) % a;
		int next_mb = (mb * (10 % b) % b + (d % b)) % b;
		(ans += dq(i + 1, next_ma, next_mb)) %= MOD;
	}

	return dp[i][ma][mb] = ans;
}

int main(){
	freopen("gen.out", "r", stdin);
	freopen("ans.out", "w", stdout);
	cin >> n >> a >> b;	

	memset(dp, -1, sizeof dp);
	cout << dq();
	return 0;
}