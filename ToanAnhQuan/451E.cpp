#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

typedef long long ll;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2); 
	if (n & 1) return ans * ans % MOD * x % MOD;
	return ans * ans % MOD;
}

int const N = 21;
ll fact[N], inv[N];
void init(){
	fact[0] = inv[0] = 1;
	for (ll i = 1; i < N; i++){
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

ll C(ll k, ll n){
	if (k > n) return 0;
	ll ans = 1;
	for (ll i = n; i > n - k; i--)
		ans = ans * (i % MOD) % MOD;
	ans = ans * inv[k] % MOD;
	return ans;
}

int main(){
	ll n, s; cin >> n >> s;
	vector<ll> arr(n);
	for (auto &x: arr) cin >> x;

	init();

	ll ans = 0;
	for (int mask = 0; mask < (1 << n); mask++){
		ll del = 0; int dem = 0;
		for (int i = 0; i < n; i++) if (mask & (1 << i))
			del += arr[i] + 1, dem++;
		(ans += (dem & 1? -1: 1) * C(n - 1, s - del + n - 1) + MOD) %= MOD;
	}
	cout << ans;
	return 0;
}