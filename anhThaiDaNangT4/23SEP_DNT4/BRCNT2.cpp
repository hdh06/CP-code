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

bool const SINGLE_TEST = 1;

int const N = 1e7 + 1;
int const MOD = 1e9 + 7;

int fact[N], inv[N], p3[N];

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

void init(){
	fact[0] = inv[0] = p3[0] = 1;
	
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
		p3[i] = 1LL * p3[i - 1] * 3 % MOD;
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int C(int n){
	return 1LL * inv[n + 1] * fact[n] % MOD * C(n, 2 * n) % MOD;
}//catalan

int calc(int n){
	assert(n % 2 == 0);
	n /= 2;
	return 1LL * C(n) * p3[n] % MOD;
}//dem so day do dai n

int calc(int n)

void solve(){	
	int n; cin >> n;
	string s; cin >> s;
	
	debug(calc(2), calc(4), calc(0));
	debug(calc(2) * calc(2) + calc(4) + calc(2) + calc(0) + calc(0));
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
