#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;
int const N = 1e6 + 1;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * x % MOD;
	return ans * ans % MOD;
}

ll fct[N], inv[N];
void init(){
	fct[0] = inv[0] = 1;
	for (ll i = 1; i < N; i++){
		fct[i] = fct[i - 1] * i % MOD;
		inv[i] = mpow(fct[i], MOD - 2);
	}
}

ll C(ll k, ll n){
	return fct[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main(){
	init();
	int n; cin >> n;
	ll ans = fct[n];
	for (int i = 1; i <= n; i++){
		if (i % 2 == 0)
			(ans += C(n - i, n) * fct[n - i] % MOD) %= MOD;
		else ans = (ans - C(n - i, n) * fct[n - i] % MOD + MOD) % MOD;
		//cout << i << " " << C(n - i, n) << " " << fct[n - i] << "\n";
	}

	cout << ans;
	return 0;
}