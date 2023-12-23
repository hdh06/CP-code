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

int const N = 1e5 + 1;

int n;
vi g[N];

ll ans = 0;

int sz[N];

int szCal(int v, int p = -1){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p){
		sz[v] += szCal(u, v);
		ans += 2 * min(sz[u], n - sz[u]);
	}
	return sz[v];
}

int ctr(int v, int p = -1){
	for (auto u: g[v]) if (u != p)
		if (sz[u] > n / 2) return ctr(u, v);
	return v;
}

vi ord;
void DFS(int v, int p = -1){
	ord.pb(v);
	for (auto u: g[v]) if (u != p)
		DFS(u, v);	
}


void solve(){	
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	szCal(1);
	int c = ctr(1);
	
	ord.pb(0);
	for (auto u: g[c])
		DFS(u, c);
	ord.pb(c);
	
	vi p(n + 1);	
	for (int i = 1; i <= n; i++)
		p[ord[i]] = ord[i + n / 2 > n? i + n / 2 - n: i + n / 2];
	
	cout << ans << "\n";
	for (int i = 1; i <= n; i++){
		cout << p[i] << ' ';
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