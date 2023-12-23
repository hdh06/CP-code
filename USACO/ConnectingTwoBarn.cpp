//http://www.usaco.org/index.php?page=viewproblem2&cpid=1159

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

int const N = 1e5 + 1;
int n, m;
vi g[N];

int ccid[N], id = 0;

vi cc[N];

void DFS(int v){
	if (ccid[v]) return;
	ccid[v] = id;
	for (int u: g[v]) DFS(u);
}

ll dis(int a, int b){
	int ans = INT_MAX;
	for (int x: cc[a]){
		int k = lb(all(cc[b]), x) - cc[b].begin();
		if (k) ans = min(ans, abs(x - cc[b][k - 1]));
		if (k < cc[b].size()) ans = min(ans, abs(x - cc[b][k]));
	}
	
	return 1LL * ans * ans;
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) g[i].clear(), cc[i].clear(), ccid[i] = 0;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	id = 0;
	for (int i = 1; i <= n; i++) if (!ccid[i]){
		++id;
		DFS(i);
	}
	for (int i = 1; i <= n; i++) cc[ccid[i]].pb(i);
	
	ll ans = dis(ccid[1], ccid[n]);
	for (int i = 2; i <= id - 1; i++) 
		ans = min(ans, dis(i, ccid[1]) + dis(i, ccid[n]));
	
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