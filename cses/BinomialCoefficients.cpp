#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;
int const N = 1e6 + 1;

ll fact[N] = {};

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n&1) return ((ans*ans)%MOD*(x%MOD))%MOD;
	return ans*ans %MOD;
}

void init(){
	fact[0] = 1;
	for (ll i = 1; i < N; i++){
		fact[i] = fact[i - 1]*i %MOD;
	}
}

ll C(ll a, ll b){
	return fact[a]*mpow(fact[b]*fact[a - b] %MOD, MOD - 2) %MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	init();
	int n; cin >> n;	
	while (n--){
		ll a, b;
		cin >> a >> b;
		cout << C(a, b) << "\n";
	}
	return 0;
}