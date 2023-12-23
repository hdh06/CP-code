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

int C3(ll n){
	if (n < 3) return 0;
	int ans = 1;
	bool a = 1, b = 1;
	for (ll i = n; i > n - 3; i--){
		ll x = i;
		if (a && x % 2 == 0) a = 0, x /= 2;
		if (b && x % 3 == 0) b = 0, x /= 3;
		ans = 1LL * ans * (x % MOD) % MOD;
	}
	return ans;
}

void solve(){	
	vl L(4), H(4);
	for (int i = 0; i < 4; i++)
		cin >> L[i] >> H[i];
	ll N; cin >> N;
	ll M = N - L[0] - L[1] - L[2] - L[3];
	int ans = 0;
		
	for (int mask = 0; mask < (1 << 4); mask++){
		ll z = M;
		for (int i = 0; i < 4; i++) if (mask & (1 << i))
			z -= H[i] - L[i] + 1; 
		
		(ans += ((__builtin_popcount(mask) & 1? -1LL: 1LL) * C3(z + 3) + MOD) % MOD) %= MOD;
	}
	
	assert(ans >= 0);
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