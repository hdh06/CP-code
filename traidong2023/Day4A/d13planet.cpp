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

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

bool const SINGLE_TEST = 1;

int const N = 1e5 + 5;
int const L = 25;
int const MOD = 1e9 + 7;

int n;
int c[N];

int g[N][L];

int dp[N];
int psum[N];

int query(int l, int r){
	int k = log2(r - l + 1);
	return gcd(g[l][k], g[r - (1 << k) + 1][k]);
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
		
	// for (int i = 1; i <= n; i++){
		// if (c[i] == 1){
			// cout << 0;
			// return;
		// }
	// }
	
		
	int zzz[N] = {};
	
	int ans = 0;
	for (int k = 0; k <= n - 1; k++){
		if (k && c[1] == gcd(c[1], c[n - k + 1])){
			(ans += dp[n - k]) %= MOD;
			if (zzz[n - k] > 1) ans = (ans - 1 + MOD) % MOD;
			continue;
		}
		if (k) c[1] = gcd(c[1], c[n - k + 1]);
		if (c[1] == 1) break;
		// debug(c[1]);
		
		for (int i = 1; i <= n; i++)
			g[i][0] = c[i];
		for (int j = 1; j < L; j++)
			for (int i = 1; i <= n; i++)
				g[i][j] = gcd(g[i][j - 1], g[min(n, i + (1 << (j - 1)))][j - 1]);
		
		dp[0] = 1;
		psum[0] = 1;
		for (int i = 1; i <= n; i++){
			int pos = i;
			for (int l = 1, r = i; l <= r;){
				int mid = (l + r) >> 1;
				if (query(mid, i) > 1){
					pos = mid;
					r = mid - 1;
				}else l = mid + 1;
			}
			
			dp[i] = (psum[i - 1] - (pos - 2 >= 0? psum[pos - 2] : 0) + MOD) % MOD;
			psum[i] = (psum[i - 1] + dp[i]) % MOD;
		}
		zzz[0] = 0;
		for (int i = 1; i <= n; i++)
			zzz[i] = gcd(zzz[i - 1], c[i]);
		(ans += dp[n - k]) %= MOD;
		if (k && zzz[n - k] > 1) ans = (ans - 1 + MOD) % MOD;
		// debug(vi(dp + 1, dp + n + 1));  	  	
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