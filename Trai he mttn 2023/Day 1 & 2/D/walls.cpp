#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int MOD;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
}

namespace sub35{
	int const N = 1e6 + 1;
	int fact[2 * N], inv[N];

	void init(){
		fact[0] = inv[0] = 1;
		for (int i = 1; i < 2 * N; i++)
			fact[i] = 1LL * fact[i - 1] * (i % MOD) % MOD;
		for (int i = 1; i < N; i++)
			inv[i] = mpow(fact[i], MOD - 2);

	}
	int C(ll k, ll n){
		return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
	}

	void solve(){
		int t; cin >> t >> MOD;
		init();
		while (t--){
			ll n, c; cin >> n >> c;
			cout << (C(c, n + c) - 1 + MOD) % MOD << "\n";
		}
	}
}

namespace sub4{
	int const N = 1e6 + 1;
	int fact[N];
	void init(){
		fact[0] = 1;
		for (int i = 1; i < N; i++)
			fact[i] = 1LL * fact[i - 1] * i % MOD;
	}

	int C(ll k, ll n){
		int p = 1;
		for (ll i = n - k + 1; i <= n; i++)
			p = 1LL * p * (i % MOD) % MOD;
		
		return 1LL * p * mpow(fact[k], MOD - 2) % MOD;
	}

	void solve(){
		int t; cin >> t >> MOD;
		init();
		while (t--){
			ll n, c; cin >> n >> c;
			cout << (C(c, n + c) - 1 + MOD) % MOD << "\n";
		}
	}
}

namespace sub12{
	int const N = 5001;
	int preC[N][2 * N];
	void init(){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < 2 * N; j++){
				if (i > j) preC[i][j] = 0;
				if (i == j) preC[i][j] = 1;
				if (i < j) preC[i][j] = (preC[i - 1][j - 1] + preC[i][j - 1]) % MOD;
				if (i == 0 || j == 0) preC[i][j] = 1;
			}
		}
	}
	void solve(){
		int t; cin >> t >> MOD;
		init();
		while (t--){
			int n, c; cin >> n >> c;
			cout << (preC[c][n + c] - 1 + MOD) % MOD << " ";
		}
	}
}

namespace sub5{
	int const N = 2e6 + 1;
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
		int t; cin >> t >> MOD;
		init();
		while (t--){
			int n, c; cin >> n >> c;
			cout << (C(c, n + c) - 1 + MOD) % MOD << "\n";
		}
	}
}

#define file "walls"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int sub; cin >> sub;
	if (sub == 1 || sub == 2) sub12::solve();
	if (sub == 3) sub35::solve();
	if (sub == 4) sub4::solve();
	if (sub == 5) sub5::solve();
	return 0;
}