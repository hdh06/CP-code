#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const P = 1000003;

int fact[P] = {};
int inv[P] = {};

ll mpow(ll x, ll n, ll m){
	if (n == 0) return 1 % m;
	ll ans = mpow(x, n / 2, m);
	if (n & 1) return ans * ans % m * x % m;
	return ans * ans % m;
}


void init(){
	fact[0] = inv[0] = 1;
	for (ll i = 1; i < P; i++){
		fact[i] = 1LL * fact[i - 1] * i % P;
		inv[i] = mpow(fact[i], P - 2, P);
	}
}

ll C(ll k, ll n){
	if (k > n) return 0;
	if (k == n) return 1;
	return 1LL * fact[n] * inv[k] % P * inv[n - k] % P;
}

ll calc(ll k, ll n){
	if (k > n) return 0;
	ll ans = 1;
	for (ll a = k, b = n; a > 0 || b > 0; a /= P, b /= P){
		ans = 1LL * ans * C(a % P, b % P) % P;
		//cout << C(a % P, b % P) << " " << a % P << " " << b % P << "\n";
	}
	return ans;
}

int main(){
	init();
	int t;
	cin >> t;
	while (t--){
		ll x, y, u, v; cin >> x >> y >> u >> v;
		if (x > u || y > v) cout << "-1\n";
		else
			cout << calc(u - x, u - x + v - y) << "\n";
	}
	return 0;
}