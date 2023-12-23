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

int const N = 1e6 + 1;
int const MOD = 1e9 + 7;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * (x % MOD) % MOD;
	return ans * ans % MOD;
}

ll fact[N], inv[N], p3[N];

void init(){
	p3[0] = fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
		p3[i] = p3[i - 1] * 3 % MOD;
	}
}


ll C(ll k, ll n){
	if (k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void solve(){
	ll n, k; cin >> n >> k;
	
	if (k == 0){
		cout << mpow(3, n);
		return;
	}
	
	ll ans = 0;
	for (ll x = 1; x <= n; x++){
		(ans += p3[n - x + 1] * C(x / 2 - 1, k - 1) % MOD * C((x + 1) / 2 - 1, n - k - 1) % MOD) %= MOD; 
		(ans += p3[n - x] * C((x + 1) / 2 - 1, k - 1) % MOD * C(x / 2 - 1, n - k - 1) % MOD) %= MOD;	
	}
	cout << ans;
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