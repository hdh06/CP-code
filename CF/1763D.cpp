#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

int const N = 101;
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
	if (k > n || k < 0 || n < 0) return 0;
	return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}


void solve(){
	int n, i, j, x, y; cin >> n >> i >> j >> x >> y;
	int ans = 0;
	if (x > y){
		i = n - i + 1, j = n - j + 1;
		swap(i, j);
		swap(x, y);
	}
	
	if (j == n && y == n){
		cout << "0\n";
		return;
	}
	
	if (y == n){
			(ans += 1LL * C(i - 1, x - 1) * C(j - i - 1, y - x - 1) % MOD) %= MOD;
	}else{
		int del = 1LL * C(i - 1, x - 1) * C(n - j - (x - i), y - x - 1) % MOD;
		int beta = 1LL * C(i - 1, x - 1) * C(j - i - 1, y - x - 1) % MOD;
		for (int k = i + 1; k < j; k++)
			(ans += 1LL * del * C(j - k - 1, n - y - 1) % MOD) %= MOD;
		for (int k = j + 1; k <= n - 1; k++)
			(ans += 1LL * beta * C(k - j - 1, n - y - 1) % MOD) %= MOD;
	}
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	init();
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!