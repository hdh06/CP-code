#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const MOD = 1e9 + 7;

int main(){
	ll n; cin >> n;
	ll ans = 0;	
	
	for (ll l = 1; l <= n;){
		ll x = n / l;
		ll r = n / x;
		// n / [l, r] == x
		(ans += (x % MOD) * ((r - l + 1) % MOD) % MOD * ((l + r) % MOD) % MOD * 500000004 % MOD) %= MOD;
		l = r + 1;
	}
	
	cout << ans;
	return 0;
}		

/*------sol 1--------
	for (ll x = 1; x * x <= n; x++)
		(ans += 1ULL * (x % MOD) * ((n / x) % MOD) % MOD) %= MOD;
	
	for (ll x = 1; x * x <= n; x++){
		ll a = n / x, b = n / (x + 1);
		if (a <= n / a) break;;
		a %= MOD, b %= MOD;
		ll cnt =(1LL * (1ULL * a * (a + 1) % MOD * 500000004 % MOD)
			   - 1LL * (1ULL * b * (b + 1) % MOD * 500000004 % MOD) 
			   + MOD) % MOD;
		(ans += 1ULL * cnt * (x % MOD) % MOD) %= MOD;
	}
*/
