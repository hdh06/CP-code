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
#define file "tcq"

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

int const N = 5e5 + 1;

int sub;
int n;
int c[N];
vi g[N];

int q;
ii queries[N];

namespace sub12{
	int const N = 5005;
	int cnt[N][N];
	int sum[N][N];
		
	void DFS(int v, int p = -1){
		cnt[v][c[v]] = 1;
		for (auto u: g[v]) if (u != p)
			DFS(u, v);
		for (int i = 1; i <= n; i++)
			for (auto u: g[v]) if (u != p)
				cnt[v][i] += cnt[u][i];
	}
	
	void solve(){
		DFS(1);
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) sum[i][cnt[i][j]]++;
			for (int j = n; j >= 1; j--)
				sum[i][j] += sum[i][j + 1];
		}
		
		for (int i = 1; i <= q; i++)
			cout << sum[queries[i].st][queries[i].nd] << " ";
	}
}

// namespace sub3{
	// int in[N], out[N], id = 0;
	// void DFS(int v, int p = -1){
		// in[v] = ++id;
		// for (auto u: g[v]) if (u != p)
			// DFS(u, v);
		// out[v] = id;
	// }
	// int psum[N][51]; 
// 	
	// void solve(){
		// DFS(1);
// 		
		// for (int i = 1; i <= n; i++)
			// psum[in[i]][c[i]] = 1;
// 		
		// for (int j = 1; j <= 50; j++)
			// for (int i = 1; i <= n; i++)
				// psum[i][j] += psum[i - 1][j];
// 				
		// for (int i = 1; i <= q; i++){
			// int cnt = 0;
			// int l = in[queries[i].st];
			// int r = out[queries[i].st];
			// for (int j = 1; j <= 50; j++)
				// if (psum[r][j] - psum[l - 1][j] >= queries[i].nd) cnt++;
			// cout << cnt << " ";
		// }
	// }
// }

namespace sub4{
	int sz[N];
	void DFS(int v, int p = -1){
		sz[v] = 1;
		for (auto u: g[v]) if (u != p){
			DFS(u, v);
			sz[v] += sz[u];
		}
	}
	
	void solve(){
		DFS(1);
		
		for (int i = 1; i <= q; i++){
			if (queries[i].nd > 1) cout << 0 << " ";
			else
				cout << sz[queries[i].st] << " ";
		}
	}
}

namespace sub7{
	int cnt[N];
	int tree[N];
	void upd(int x, int v){
		// x++;
		for (;x < N; x += x & -x) tree[x] += v;
	}
	int get(int x){
		// x++;
		int ans = 0;
		for (;x > 0; x -= x & -x) ans += tree[x];
		return ans;
	}
	void insert(int u){
		// debug("+", u);
		if (cnt[c[u]] > 0) upd(cnt[c[u]], -1);
		cnt[c[u]]++;
		upd(cnt[c[u]], 1);
	}
	void remove(int u){
		// debug("-", u);
		upd(cnt[c[u]], -1);
		cnt[c[u]]--;
		if (cnt[c[u]] > 0) upd(cnt[c[u]], 1);
	}
	int query(int k){
		return get(N - 1) - get(k - 1);
	}
	
	int in[N], out[N], id = 0;
	void DFS(int v, int p = -1){
		in[v] = ++id;
		for (auto u: g[v]) if (u != p)
			DFS(u, v);
		out[v] = id;
	}
	
	vi nque[N];
	
	int p[N];
	int ans[N];
	
	void calc(int v, int par = -1){
		int maxU = -1;
		for (auto u: g[v]) if (u != par) if (maxU == -1 || out[u] - in[u] > out[maxU] - in[maxU])
			maxU = u;
		
		if (maxU == -1){
			insert(v);
			for (auto x: nque[v])
				ans[x] = query(queries[x].nd);
			return;
		}
		
		for (auto u: g[v]) if (u != par && u != maxU){
			calc(u, v);
			for (int i = in[u]; i <= out[u]; i++){
				// debug(u, i, p[i], in[u], out[u]);
				remove(p[i]);
			}
		}
		calc(maxU, v);
		for (auto u: g[v]) if (u != par && u != maxU)
			for (int i = in[u]; i <= out[u]; i++)
				insert(p[i]);
			
		insert(v);
		for (auto x: nque[v])
			ans[x] = query(queries[x].nd);
	}
	
	void solve(){
		DFS(1);
		for (int i = 1; i <= q; i++)
			nque[queries[i].st].pb(i);
		
		
		for (int i = 1; i <= n; i++)
			p[in[i]] = i;
		// debug(vi(in + 1, in + n + 1));
		// debug(vi(p + 1, p + n + 1));
			
		calc(1);
		
		for (int i = 1; i <= q; i++)
			cout << ans[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> sub;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
 	cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> queries[i].st >> queries[i].nd;

	// if (sub == 1|| sub == 2)
		// sub12::solve();
	// // if (sub == 3)
		// // sub3::solve();
	// else if (sub == 4) 
		// sub4::solve();
	// else 
		sub7::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!