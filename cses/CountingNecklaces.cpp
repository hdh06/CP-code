#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int main(){
	int n, m; cin >> n >> m;	
	int ans = 0;
	for (int i = 0; i < n; i++) (ans += mpow(m, __gcd(i, n))) %= MOD;
	
	ans = 1LL * ans * mpow(n, MOD - 2) % MOD;
	cout << ans;
	return 0;
}