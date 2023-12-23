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
int const MOD = 998244353;
int const N = 3e5 + 1;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * (x % MOD) % MOD;
	return ans * ans % MOD;
}

bool isPrime(ll x){
	if (x < 2) return 0;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

ll dp[N];

void solve(){		
	ll n, m; cin >> n >> m;
	
	ll ans = 0;
	dp[2] = 0;
	ll t = 1;
	for (int i = 2; i <= n; i++){
		if (isPrime(i)) t *= i;
		ll y = m - m / t;	
		dp[i] = 1LL * mpow(m, i - 1) * (y % MOD) % MOD;
		(dp[i] += 1LL * dp[i - 1] * ((m - y) % MOD) % MOD) %= MOD;
		(ans += dp[i]) %= MOD;
	}
	cout << ans;
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