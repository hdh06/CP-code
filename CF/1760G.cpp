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
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

int const N = 1e5 + 1;

int n, a, b;
set<int> cnt;

vector<ii> g[N];

void dfs1(int v, int x, int p = 0){
	if (v == b) return;
	cnt.insert(x);
	for (auto e: g[v]) if (e.st != p)
		dfs1(e.st, x ^ e.nd, v);
}

bool dfs2(int v, int x, int p = 0){
	if (v != b)
		if (cnt.find(x) != cnt.end()) return 1;
	
	bool ans = 0;
	for (auto e: g[v]) if (e.st != p)
		ans |= dfs2(e.st, x ^ e.nd, v);
	return ans;
}

void solve(){
	cin >> n >> a >> b;
	
	cnt.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
	
	for (int i = 2; i <= n; i++){
		int x, y, w; cin >> x >> y >> w;
		g[x].pb({y, w});
		g[y].pb({x, w});	
	}
	
	dfs1(a, 0);
	cout << (dfs2(b, 0)? "YES\n" : "NO\n");
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
}//it's coding time!