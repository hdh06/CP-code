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

int const N = 105;

int n, m, R;
vii cars[N];

vii g[N * 1000 + N];

int len0, pos0;

//encode: i * 1000 + j -> range has l as j at lane i

int node(int i, int j){return i * 1000 + j;}

int node0;

int cvis = 0;
int vis[N * 1000 + N];

void DFS(int v, int k){
	if (vis[v] == cvis) return;
	vis[v] = cvis;
	for (auto u: g[v]) if (u.nd >= k) DFS(u.st, k);
}

bool f(int k){
	cvis++;
	DFS(node0, k);
	for (int i = 0; i < sz(cars[n]); i++)
		if (vis[node(n, i)] == cvis) return true;
	return false;
}

void solve(){	
	cin >> n >> m >> R;
	cin >> len0 >> len0 >> pos0;
	for (int i = 1; i <= n; i++) cars[i].pb({0, 0});
	for (int i = 2; i <= m; i++){
		int lane, len, pos; cin >> lane >> len >> pos;
		lane++;
		cars[lane].pb({len, pos});
	}
	
	for (int i = 1; i <= n; i++){
		cars[i].pb({0, R});
		sort(all(cars[i]), [](ii a, ii b){
			return a.nd < b.nd;
		});
	}
	
	node0 = 0;
	while (cars[1][node0 + 1].st + cars[1][node0 + 1].nd <= pos0) node0++;
	
	int z = 2 * min(pos0 - cars[1][node0].st - cars[1][node0].nd, cars[1][node0 + 1].nd - pos0 - len0);
	
	node0 = node(1, node0);
	
	for (int i = 1; i < n; i++){
		for (int j = 0; j < cars[i].size() - 1; j++)
			for (int k = 0; k < cars[i + 1].size() - 1; k++){
				int a = cars[i][j].st + cars[i][j].nd;
				int b = cars[i][j + 1].nd;
				int c = cars[i + 1][k].st + cars[i + 1][k].nd;
				int d = cars[i + 1][k + 1].nd;
				
				int l = max(a, c);
				int r = min(b, d);
				
				
				if (r - l >= len0){
					g[node(i, j)].pb({node(i + 1, k), r - l});	
					g[node(i + 1, k)].pb({node(i, j), r - l});
				}
			}
	}
	
	int ans = -1;
	for (int l = len0, r = R; l <= r;){
		int mid = (l + r) >> 1;
		if (f(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}

	if (ans == -1) cout << "Impossible";
	else cout << setprecision(5) << fixed << min(z, ans - len0) * 0.5L;
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