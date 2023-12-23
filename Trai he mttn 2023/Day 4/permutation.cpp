#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const MOD = 1e9 + 7;

int const N = 1e6 + 5;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
 }

int fact[N], inv[N];

void init(){
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int dp[N], sz[N];

int main(){
	init();
	int n, k; cin >> n >> k;
	
	if (k == 1){
		cout << 0;
		return 0;
	}
	
	for (int i = n; i >= 0; i--){
		sz[i] = dp[i] = 1;
		for (ll j = 1LL * i * k + (i == 0); j <= min(1LL * n, 1LL * i * k + k - 1); j++)
			sz[i] += sz[j];
		int tmp = sz[i] - 1;
		for (ll j = 1LL * i * k + (i == 0); j <= min(1LL * n, 1LL * i * k + k - 1); j++){
			dp[i] = 1LL * dp[i] * C(sz[j], tmp) % MOD * dp[j] % MOD; 
			tmp -= sz[j];
		}
	}

	cout << dp[0] << "\n";
	return 0;
}