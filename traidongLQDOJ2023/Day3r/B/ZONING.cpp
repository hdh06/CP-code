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
#define file "ZONING"

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

int const N = 3e5 + 1;

struct edge{
	int a, b, id;
	edge(){}
	edge(int a, int b, int id):a(a), b(b), id(id) {}
};

int n, m;
vector<edge> edl;
vi keep;

namespace sub1{
	int lk[N];
	int find(int v){return lk[v] = lk[v] == v? v: find(lk[v]);}

	bool unite(int a, int b){
		a = find(a), b = find(b);
		if (a == b) return false;
		lk[a] = b;
		return true;
	}

	void solve(){
		vi p(m);
		iota(all(p), 1);
		sort(all(keep));
		do{
			iota(lk + 1, lk + n + 1, 1);
			sort(all(edl), [&](edge a, edge b){
				return p[a.id - 1] < p[b.id - 1];
			});

			vi z;
			for (auto x: edl) if (unite(x.a, x.b)) z.pb(x.id);
			sort(all(z));
			// debug(z);
			if (z == keep){
				for (auto x: p) cout << x << " ";
				return;
			}
		}while (next_permutation(all(p)));
	}
}

namespace sub2{
	vii g[N];
	ii p[N]; int h[N];
	void DFS(int v){
		for (auto u: g[v]) if (u.st != p[v].st){
			h[u.st] = h[v] + 1;
			p[u.st] = mp(v, u.nd);
			DFS(u.st);
		}
	}

	int ans[N];
	bool need[N];
	bool used[N];
	int mex(){
		int ans = 1;
		for (int i = 1; i <= m; i++) if (used[ans]) ans++;
		return ans;
	}
	void solve(){
		for (auto x: keep) need[x] = 1;
		for (auto e: edl) if (need[e.id]) g[e.a].pb({e.b, e.id}), g[e.b].pb({e.a, e.id});
		DFS(1);
		for (int i = 0; i < m; i++){
			int a = edl[i].a, b = edl[i].b;
			if (need[i + 1]){
				if (!ans[i + 1]){
					int x = mex();
					ans[i + 1] = x;
					used[x] = 1;
					// debug(i + 1, x);
				}
				continue;
			}
			vi z;
			if (h[a] > h[b]) swap(a, b);
			while (h[b] > h[a]){
				z.pb(p[b].nd);
				b = p[b].st;
			}
			while (a != b){
				z.pb(p[a].nd);
				z.pb(p[b].nd);
				a = p[a].st;
				b = p[b].st;
			}	

			sort(all(z));
			
			int curr = 1;
			int maxx = 0;
			for (auto x: z){
				if (!ans[x]){
					while (used[curr]) curr++;
					ans[x] = curr;
					used[curr] = 1;
					// debug(x, curr);
				}
				maxx = max(maxx, ans[x]);

			}

			// debug(z, maxx);

			ans[i + 1] = maxx + 1;
			// debug(ans[i]);
			// debug(i + 1, maxx + 1);
			used[maxx + 1] = 1;
		}

		for (int i = 1; i <= m; i++)
			cout << ans[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		edl.pb(edge(a, b, i));
	}

	for (int i = 1; i < n; i++){
		int x; cin >> x;
		keep.pb(x);
	}

	// if (n <= 9 && m <= 9)
	// 	sub1::solve();
	// else
		sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!