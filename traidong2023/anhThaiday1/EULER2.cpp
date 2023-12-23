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
#define file "flie"

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

int const MOD = 1e9 + 7;

int mpow(ll x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	ll n, k; cin >> n >> k;	
	
	int kgt = 1;
	for (int i = 1; i <= k - 1; i++) kgt = 1LL * kgt * i % MOD;
	int invkgt = mpow(kgt, MOD - 2);
	
	ll ans = 1;
	for (ll i = n + k - 1; i > n; i--)
		ans = ans * (i % MOD) % MOD;
	ans = ans * invkgt % MOD;
	
	kgt = 1;
	for (int i = 1; i <= k; i++) 
		kgt = 1LL * kgt * i % MOD;
	// debug(kgt);
	invkgt = mpow(kgt, MOD - 2);
	ans = ans * invkgt % MOD;
	
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!