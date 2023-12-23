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
#define file "walls"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;
int MOD;

int const C = 1e6 + 1;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * (x % MOD) % MOD;
	return ans * ans % MOD;
}

ll inv[C];
void init(){
	inv[0] = 1;
	ll tmp = 1;
	for (ll i = 1; i < C; i++){
		(tmp *= i % MOD) %= MOD;
		inv[i] = mpow(tmp, MOD - 2);
	}
}

void solve(){
	ll n, c; cin >> n >> c;
	ll ans = 1;
	for (ll i = n + 1; i <= n + c; i++)
		(ans *= i % MOD) %= MOD;
	
	(ans *= inv[c]) %= MOD;
	
	cout << (ans - 1 + MOD) % MOD << " ";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int s; cin >> s;
	int t; cin >> t;
	cin >> MOD;
	init();
	while (t--) solve();
	return 0;
}//it's coding time!