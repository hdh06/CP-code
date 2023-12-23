#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;

ll mpow(ll x, ll n, ll mod){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2, mod);
	if (n & 1) return ans * ans % mod * x % mod;
	return ans * ans % mod;
}

ll C(ll k, ll n){
	if (k > n) return 0;
	ll ans = 1, m = 1;
	for (ll i = n; i > n - k; i--) (ans *= i) %= MOD;
	for (ll i = 1; i <= k; i++) (m *= i) %= MOD;

	return ans * mpow(m, MOD - 2, MOD) % MOD;	
}

int main(){
	ll n, m; cin >> n >> m;
	cout << C(n - 1, m + n - 1);
	return 0;
}