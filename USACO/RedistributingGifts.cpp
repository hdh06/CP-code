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

int n;
vi g[N], rg[N];

bool vis[N];
vi path;
void dfs(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) dfs(u);
	path.pb(v);
}

int ccid[N], id = 0;
void ksj(int v){
	if (ccid[v]) return;
	ccid[v] = id;
	for (auto u: rg[v]) ksj(u);
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++){
		bool y = 1;
		for (int j = 1; j <= n; j++){
			int x; cin >> x;
			if (y) g[i].pb(x), rg[x].pb(i);
			if (i == x) y = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) dfs(i);	
	reverse(all(path));
	
	for (auto x: path) if (!ccid[x]){
		++id;
		ksj(x);
	}
	
	for (int i = 1; i <= n; i++)
		for (int x: g[i]) if (ccid[x] == ccid[i]){
			cout << x << "\n";
			break;
		}
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