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

int const N = 1e6 + 1;
int const MOD = 998244353;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
}

bool sang[N] = {1, 1};
int fact[N], inv[N];
void init(){
	for (ll i = 2; i < N; i++) if (!sang[i])
		for (ll j = i * i; j < N; j += i) 
			sang[j] = true;
		
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

int cnt[N] = {};
vi v;

int dp[4045][2023];

int calc(int n, int k){
	if (k == 0) return 1;
	if (n == 0) return 0;
	
	if (dp[n][k] != -1) return dp[n][k];
	
	return dp[n][k] = (calc(n - 1, k) + 1LL * calc(n - 1, k - 1) * cnt[v[n]] % MOD) % MOD;
}

void solve(){	
	init();
	int n; cin >> n;
	
	set<int> s;
	for (int i = 1; i <= 2 * n; i++){
		int x; cin >> x;
		cnt[x]++;
		if (!sang[x]) s.insert(x);
	}
	
	int z = fact[n];
	for (int i = 1; i < N; i++)
		z = 1LL * z * inv[cnt[i]] % MOD;
	
	s.insert(0);
	v = vi(all(s));
	
	memset(dp, -1, sizeof dp);
	
	cout << 1LL * z * calc(v.size() - 1, n) % MOD << "\n";
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