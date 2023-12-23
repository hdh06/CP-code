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

bool const SINGLE_TEST = 1;

int const N = 5001;

int n, mod;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % mod * x % mod;
	return 1LL * ans * ans % mod;
}

int fact[N], inv[N];

int C(int k, int n){
	if (k > n || k < 0 || n < 0) return 0;
	return 1LL * fact[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve(){
	cin >> n >> mod;
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % mod;
		inv[i] = mpow(fact[i], mod - 2);
	}
	
	int ans = (n & 1? 0: fact[n - 2]);
	
	for (int i = n / 2; i <= n - 2; i++)
		for (int j = 0; j <= n - 2 - i; j++)
			(ans += 1LL * C(j, n - 2 - i) * fact[i - 1 + j] % mod * (2 * (n / 2) - i) % mod) %= mod;
		
	cout << 1LL * n * ans % mod;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!