#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;
ll const MOD = 1e9 + 7;

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

int main(){
	init();
	string s; cin >> s;
	int fre[26] = {}, n = s.size();
	for (auto x: s) fre[x - 'a']++;

	ll ans = fct[n];
	for (int i = 0; i < 26; i++) 
		(ans *= inv[fre[i]]) %= MOD;
	
	cout << ans;
	return 0;
}