#include <bits/stdc++.h>

using namespace std;

#define file "flowers"
typedef long long ll;

int t, MOD;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
}

namespace sub1234{
	int const N = 1e6 + 1;
	int fact[N], inv[N];

	void init(){
		fact[0] = inv[0] = 1;
		for (int i = 1; i < N; i++)
			fact[i] = 1LL * fact[i - 1] * (i % MOD) % MOD;
		for (int i = 1; i < N; i++)
			inv[i] = mpow(fact[i], MOD - 2);

	}
	int C(ll k, ll n){
		if (n < N)
			return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;

		ll p = 1;
		for (ll i = n - k + 1; i <= n; i++)
			p = 1LL * p * (i % MOD) % MOD; 
		return 1LL * p * inv[k] % MOD;
	}

	void solve(){
		init();
		while (t--){
			ll n, m, k; cin >> n >> m >> k;
			cout << 1LL * C(k, n - 1) * m % MOD * mpow(m - 1, k) % MOD << "\n";
		}
	}
}

namespace sub5{
	int const N = 1e6 + 1;
	bool sang[N] = {1, 1};
	vector<int> primes;
	void init(){
		for (ll i = 2; i < N; i++) if (!sang[i]){
			for (ll j = i * i; j < N; j += i)
				sang[j] = 1;
			primes.push_back(i);
		}
	}

	int lf(int n, int p){
		int ans = 0;
		for (ll i = p; i <= n; i *= p)
			ans += n / i;
		return ans;
	}


	int C(int k, int n){
		int ans = 1;
		for (auto i: primes){
			if (i > n) break;
			int p = lf(n, i) - lf(k, i) - lf(n - k, i);
			ans = 1LL * ans * mpow(i, p) % MOD;
		}
		return ans;
	}

	void solve(){
		init();
		while (t--){
			int n, m, k; cin >> n >> m >> k;
			cout << 1LL * C(k, n - 1) * (m % MOD) % MOD * mpow(m - 1, k) % MOD << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	cin >> t >> MOD;
	if (MOD == 220797) 
		sub5::solve();
	else sub1234::solve();
	return 0;
}