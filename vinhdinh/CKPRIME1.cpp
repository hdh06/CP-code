#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mpow(ll x, ll n, ll mod){
	if (n == 0) return 1 % mod;
	ll ans = mpow(x, n/2, mod);
	if (n & 1) return ((ans*ans % mod) * (x % mod)) % mod;
	return ans*ans % mod;
}

vector<ll> d = {2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 41, 1000000007};

bool primeCheck(ll n){
	if (n <= 1) return false;
	for (int t = 0; t < d.size(); t++) if (d[t] != n){
		cout << d[t] << " " << mpow(d[t], n - 1, n);
		if (mpow(d[t], n - 1, n) != 1 % n) return false;
	}
	return true;
}

int main(){
	ll n; cin >> n;

	// cout << (primeCheck(n)?"YES":"NO");
	cout << mpow(2, 68718952446, 68718952447);
	return 0;
}