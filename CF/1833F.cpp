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

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * (x % MOD) % MOD;
	return ans * ans % MOD;
}

int n, m;

void solve(){	
	cin >> n >> m;
	map<int, int> cnt;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		cnt[x]++;
	}
	
	vll a(all(cnt));
	
	ll p = 1;
	ll ans = 0;
	for (int i = 0; i < a.size(); i++){
		p = p * a[i].nd % MOD;
		if (i >= m) p = p * mpow(a[i - m].nd, MOD - 2) % MOD;
		
		if (i >= m - 1 && a[i].st - a[i - m + 1].st < m)
			(ans += p) %= MOD;
	}
	cout << ans << "\n";
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
}//khong phai _HDH, _HDH ko xai template!!!