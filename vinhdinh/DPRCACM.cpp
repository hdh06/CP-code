#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int const MOD = 1e9 + 7;

int dp[N][N] = {};

void init(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = -1;
}

int dequy(int n, int k){
	if (k == 0) return 1;
	if (dp[n][k] != -1) return dp[n][k];

	int ans = 0;

	for (int i = sqrt(n); i >= 1; i--) if (n % i == 0){
		ans += dequy(i, k - 1);
		ans %= MOD;
		if (i == n/i) continue;
		ans += dequy(n / i, k - 1);
		ans %= MOD;
	}
	return dp[n][k] = ans;
}	

int kq(int n, int k){
	int ans = 0;
	for (int i = n; i >= 1; i--) ans += dequy(i, k - 1), ans %= MOD;
	return ans;
}

int main(){
	init();
	int n, k; cin >> n >> k;
	cout << kq(n, k);
	return 0;
}