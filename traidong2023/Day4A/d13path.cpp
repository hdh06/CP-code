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
#define file "flie"

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

int const N = 5e4 + 1;
int const L = 16;

int n, m, s, q;

vi g[N];

int lvl[N], cnt[N + 1], id[N];

bitset<N> passed[N];
// bitset<N> f[N];

int p[N][L];

// vi ord;

void DFS(int v){
	for (auto u: g[v]) if (!p[u][0] && lvl[u] == lvl[v] + 1){
		p[u][0] = v;
		for (int i = 1; i < L; i++)
			p[u][i] = p[p[u][i - 1]][i - 1];
		DFS(u);
	}
	// ord.pb(v);
}
int jump(int v, int k){
	for (int i = 0; i < L; i++) if (k & (1 << i))
		v = p[v][i];
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	queue<int> que;
	que.push(s);
	lvl[s] = 1;
	while (!que.empty()){
		int v = que.front();
		que.pop();
		for (auto u: g[v]) if (!lvl[u]){
			lvl[u] = lvl[v] + 1;
			que.push(u);
		}
	}
	
	//renumber the vertex (couting sort method xd)
	for (int i = 1; i <= n; i++)
		cnt[lvl[i]]++;
	for (int i = 1; i <= n + 1; i++)	
		cnt[i] += cnt[i - 1];	
	for (int i = 1; i <= n; i++)
		id[cnt[lvl[i]]--] = i;
		//id[new_id] = old_id;
	
		
	DFS(s);
	
	for (int i = 1; i <= n; i++){
		for (auto u: g[id[i]]) if (lvl[u] == lvl[id[i]] - 1)
			passed[id[i]] |= passed[u];
		passed[id[i]][i] = 1;
	}
	
	cin >> q;
	while (q--){
		int t, d; cin >> t >> d;
		d++;
		
		int z = ((passed[t] >> (cnt[d] + 1)) << (cnt[d] + 1 + N - cnt[d + 1] - 1)).count();
		
		// debug(tmp);
		
		if (z < 1){
			cout << 0 << "\n";
		}else if (z > 1){
			cout << -1 << "\n";
		}else{
			cout << jump(t, lvl[t] - d) << "\n";
		}
	}
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!