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

int const N = 501;
int const MOD = 998244353;

int fact[N], inv[N];
int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
}

void init(){
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int n, x;

int dp[N][N];

int calc(int i, int j){
	if (i == 0) return 1;
	if (i == 1) return 0;
	
	int &ans = dp[i][j];
	if (ans != -1) return ans;
	ans = 0;
	for (int k = 0; k <= i; k++){
		int new_j = min(x, j + i - 1);
		(ans += 1LL * calc(k, new_j) * C(k, i) % MOD * mpow(new_j - j, i - k) % MOD) %= MOD;
	}
	return ans;
}

void solve(){	
	init();
	cin >> n >> x;
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(n, 0);
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