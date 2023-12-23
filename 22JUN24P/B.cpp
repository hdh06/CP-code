#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;
int const MOD = 1e9 + 7;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * x % MOD;
	return ans * ans % MOD;
}

ll fct[N], inv[N], fctt[N];
void init(){
	fct[0] = inv[0] = 1;
	for (ll i = 1; i < N; i++){
		fct[i] = fct[i - 1] * i % MOD;
		inv[i] = mpow(fct[i], MOD - 2);
	}
	fctt[0] = fctt[1] = 1;
	for (ll i = 2; i < N; i++)
		fctt[i] = fctt[i - 2] * i % MOD;
}

ll C(ll k, ll n){
	if (k > n) return 0;
	return fct[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main(){
	init();
	ll n; cin >> n;
	ll ans = 0;
	for (ll i = 0; i <= n; i++) if ((n - i) % 2 == 0)
		(ans += C(i, n) * mpow(fctt[max(n - i - 1, 0ll)], 2) % MOD) %= MOD;
	cout << ans;
	return 0;
}