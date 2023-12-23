#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int fact[N], inv[N];
void init(){
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

typedef pair<int, int> ii;
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	init();	
	int n, k; cin >> n >> k;
	vector<ii> e;
	for (int i = 1; i <= n; i++){
		int l, r; cin >> l >> r;
		e.push_back({l, 1});
		e.push_back({r + 1, -1});
	}

	sort(e.begin(), e.end());
	int ans = 0;
	for (int i = 0, dem = 0; i < 2 * n; i++){
		if (i != 0) (ans += 1LL * (1LL * e[i].st - e[i - 1].st + MOD) % MOD * C(k, dem) % MOD) %= MOD;
		dem += e[i].nd;
	}
	cout << ans << "\n";
	return 0;
}