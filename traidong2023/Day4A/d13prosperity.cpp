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

int const N = 3e5 + 1;

int n, q;
ll p[N];
vi g[N];

int trv[N], in[N], out[N], id = 0, par[N];

ll b1[N], b2[N];

void add(ll tree[], int x, ll v){
	// if (x == 0) return;
	// debug(x);
	for (;x < N; x += x & -x) tree[x] += v;
}
void upd(int l, int r, ll x){
	if (l <= 0) return;
	add(b1, l, x);
	add(b1, r + 1, -x);
	add(b2, l, x * (l - 1));
	add(b2, r + 1, -x * r);
}
ll sum(ll tree[], int x){
	// debug(x);
	ll ans = 0;
	for (;x > 0; x -= x & -x)
		ans += tree[x];
	return ans;
}

ll psum(int x){
	return sum(b1, x) * x - sum(b2, x);
}

ll get(int l, int r){
	if (l == 0) return 0;
	return psum(r) - psum(l - 1);
}

void DFS(int v){
	for (auto u: g[v]) if (u != par[v]){
		par[u] = v;
		DFS(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	
		
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);	
	}
	
	DFS(1);
	
	
	trv[1] = ++id;
	for (int i = 1; i <= n; i++){
		in[i] = INT_MAX;
		for (auto u: g[i]) if (u != par[i]){
			trv[u] = ++id;
			in[i] = min(in[i], trv[u]);
			out[i] = max(out[i], trv[u]);
		}
		if (in[i] == INT_MAX) in[i] = 0;
	}
	
	// debug(vi(trv + 1, trv + n + 1));

	for (int i = 1; i <= n; i++) upd(trv[i], trv[i], p[i]);
	
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int v; ll x; cin >> v >> x;
			upd(trv[v], trv[v], 2 * x);
			// debug(trv[v], trv[v], 2 * x);
			upd(trv[par[v]], trv[par[v]], x);
			// debug(trv[par[v]], trv[par[v]], x);
			upd(in[v], out[v], x);
			// debug(in[v], out[v], x);

		}
		if (t == 2){
			int v; cin >> v;
			cout << get(trv[v], trv[v]) + get(trv[par[v]], trv[par[v]]) + get(in[v], out[v]) << "\n";
		}
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!