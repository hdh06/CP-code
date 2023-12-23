#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * x % MOD;
	return ans * ans % MOD;
}

ll inv(ll x){
	return mpow(x, MOD - 2);
}

ll C(ll k, ll n){
	if (k > n) return 0;
	ll t = 1, m = 1;
	for (ll i = n; i > n - k; i--) (t *= i) %= MOD;
	for (ll i = 1; i <= k; i++) (m *= i) %= MOD;
	return t * inv(m) % MOD;
}

int main(){
	int n; cin >> n;
	if (n & 1){
		cout << 0;
		return 0;
	}

	n /= 2;

	cout << C(n, 2 * n) * inv(n + 1) % MOD;
	return 0;
}