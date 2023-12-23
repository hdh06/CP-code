#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "fiel"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

bool const SINGLE_TEST = 0;

int const MOD = 1e9 + 7;

ll log(ll x, ll n){
	ll ans = 0;
	while (n / x){
		ans ++;
		n /= x;
	}
	return ans;
}

ll psum[70];
void init(){
	ll n = 1e18;
	ll p = 2;
	for (ll i = 4; ; i *= 2, p++){
		ll k = (i > (n + 1) / 2? n: 2 * i - 1);
		psum[p] = psum[p - 1];
		for (ll j = 1, pj = 0; ; j *= p, pj++){	
			(psum[p] += pj * (max(0LL, (j > (k + 1) / p? k: p * j - 1) - max(i, j) + 1) % MOD) % MOD) %= MOD;
			if (j > k / p) break;
		}
		if (i > n / 2) break;
	}
}

ll calc(ll n){
	if (n <= 3) return 0;
	ll p = log(2, n);
	ll ans = psum[p - 1];
	ll i = 1LL << p;
	ll k = (i > (n + 1) / 2? n: 2 * i - 1);
	for (ll j = 1, pj = 0; ; j *= p, pj++){	
		(ans += pj * (max(0LL, (j > (k + 1) / p? k: p * j - 1) - max(i, j) + 1) % MOD) % MOD) %= MOD;
		if (j > k / p) break;
	}
	return ans;
}

void solve(){	
	ll l, r; cin >> l >> r;
	// debug(calc(6));
	cout << (calc(r) - calc(l - 1) + MOD) % MOD << "\n";
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
}//khong phai _HDH, _HDH ko xai template!!!