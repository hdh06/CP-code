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
#define file "GAME"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

int const N = 101;
int const MOD = 1e9 + 7;

int dp[N][N];
int calc(int k, int n){
	if (k > n) return 0;
	if (k == n) return 1;
	if (k == 0) return 1;
	
	if (dp[k][n]) return dp[k][n];
	
	return dp[k][n] = (calc(k - 1, n - 1) + calc(k, n - 1)) % MOD;
}

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	int a = 0, b = 0;
	for (auto x: s){
		a += (x == '1');
		b += (x == '0');
	}
	
	ll ans = 0;
	for (int i = a; i >= 0; i -= 3){
		if (i > k) continue;
		if (k - i > b) continue;
		if ((b - (k - i)) & 1) continue;
		(ans += calc(i, k)) %= MOD;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!