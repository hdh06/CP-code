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
// #define sz(x) (int)x.size()
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

int const N = 1e5 + 1;

int n, q;
int p[N];


namespace sub1{
	set<int> g[N];
	int h[N];
	int ans = 0;
	
	void DFS(int v){
		if (g[v].size() == 0) ans = max(ans, h[v]);
		for (auto u: g[v]){
			h[u] = h[v] + 1;
			DFS(u);
		}
	}
	void solve(){
		for (int i = 2; i <= n; i++)
			g[p[i]].insert(i);
		while (q--){
			int t, v; cin >> t >> v;
			// debug(t, v);
			if (t == 1){
				g[p[v]].erase(v);
				p[v] = p[p[v]];
				g[p[v]].insert(v);
				
			}
			if (t == 2){
				ans = 0;
				h[v] = 0;
				DFS(v);
				cout << ans << "\n";
			}
		}
	}
}
namespace sub4{
	vi g[N];
	int tree[N << 2];
	void upd(int pos, int val, int x = 1, int l = 1, int r = n){
		if (r < pos || pos < l) return ;
		if (l == r){
			tree[x] = val;
			return;
		}
		int mid = (l + r) >> 1;
		upd(pos, val, 2 * x, l, mid);
		upd(pos, val, 2 * x + 1, mid + 1, r);
		tree[x] = max(tree[2 * x], tree[2 * x + 1]);
	}
	
	int get(int L, int R, int x = 1, int l = 1, int r = n){
		if (r < L || R < l) return 0;
		if (L <= l && r <= R) return tree[x];
		int mid = (l + r) >> 1;
		return max(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
	}
	
	int h[N], tin[N], tut[N], id = 0;
	bool isLeaf[N];
	void DFS(int v){
		tin[v] = ++id;
		for (auto u: g[v]){
			h[u] = h[v] + 1;
			DFS(u);
		}
		tut[v] = id;
	}
	void solve(){
		// for (int i = 0; i < N; i++) tree[i] = INT_MAX;
		for (int i = 2; i <= n; i++)
			g[p[i]].pb(i);
		DFS(1);
		for (int i = 1; i <= n; i++) upd(tin[i], h[i]);
		
		// debug(vi(h + 1, h + n + 1));
		
		while (q--){
			int t, v; cin >> t >> v;
			if (t == 1){
				if (p[v] == 1) continue;
				h[v]--;
				isLeaf[v] = 1;
				upd(tin[v], h[v]);
				
			}
			if (t == 2){
				// debug(get(tin[v], tut[v]));
				// if (sz[v] == 0) cout << 0 << "\n";
				if (isLeaf[v]){
					cout << 0 << "\n";
					continue;
				}
				cout << max(0, get(tin[v], tut[v]) - h[v]) << "\n";
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> n >> q;
	p[1] = 1;
	for (int i = 2; i <= n; i++) cin >> p[i];
	
	sub4::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!