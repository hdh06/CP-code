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

int const N = 5001;

int n;

vi g[N];
int sz[N];

void DFS(int v){
	sz[v] = 1;
	for (auto u: g[v]){
		DFS(u);
		sz[v] += sz[u];
	}
}

void solve(){	
	int n; cin >> n;
	for (int i = 2; i <= n; i++){	
		int x; cin >> x;
		g[x].pb(i);
	}
	
	DFS(1);
	
	// debug(vi(sz + 1, sz + n + 1));
	
	bitset<N> dp;
	
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		dp = 1;
		for (auto u: g[i])
			dp |= dp << sz[u];
		
		ll maxx = 0;	
		for (int j = 1; j < sz[i] - 1; j++) if (dp[j])
			maxx = max(maxx, 1LL * j * (sz[i] - 1 - j));
		ans += maxx;
	}
	cout << ans;
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