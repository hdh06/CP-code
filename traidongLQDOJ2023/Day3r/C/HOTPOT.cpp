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
#define file "HOTPOT"

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

int n, k;
vii g[N];

namespace sub1{
	int const L = 20;
	int p[N][L], h[N], maxx[N][L];
	void DFS(int v){
		for (auto e: g[v]) if (e.st != p[v][0]){
			int u = e.st, w = e.nd;
			h[u] = h[v] + 1;
			p[u][0] = v;
			for (int i = 1; i < L; i++) p[u][i] = p[p[u][i - 1]][i - 1];
			maxx[u][0] = w;
			for (int i = 1; i < L; i++) maxx[u][i] = max(maxx[u][i - 1], maxx[p[u][i - 1]][i - 1]);
			DFS(u);
		}
	}

	int LCA(int a, int b){
		if (h[a] > h[b]) swap(a, b);
		int k = h[b] - h[a];
		for (int i = 0; i < L; i++) if (k & (1 << i)) b = p[b][i];
		if (a == b) return a;
		for (int i = L - 1; i >= 0; i--) if (p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
		return p[a][0];
	}

	int getMax(int a, int b){
		if (h[a] > h[b]) swap(a, b);
		int k = h[b] - h[a];
		int ans = 0;
		for (int i = 0; i < L; i++) if (k & (1 << i)) ans = max(ans, maxx[b][i]), b = p[b][i];
		if (a == b) return ans;
		for (int i = L - 1; i >= 0; i--) if (p[a][i] != p[b][i]){
			ans = max(ans, maxx[a][i]);
			ans = max(ans, maxx[b][i]);
			a = p[a][i], b = p[b][i];
		}
		return max(ans, max(maxx[a][0], maxx[b][0]));
	}
	int getDis(int a, int b){
		return h[a] + h[b] - 2 * h[LCA(a, b)];
	}

	void solve(){
		DFS(1);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ans += (getMax(i, j) - getDis(i, j) >= k);
			
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b, w; cin >> a >> b >> w;
		g[a].pb({b, w});
		g[b].pb({a, w});
	}

	if (n <= 1000)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!