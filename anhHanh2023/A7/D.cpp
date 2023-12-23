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
#define file "mmgraph"

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

int const N = 501;

int sub;
int n, m;
ll w[N];

struct edge{
	int a, b; ll w;
	edge(){}
	edge(int a, int b, ll w) :a(a), b(b), w(w) {}
};

vector<edge> edl;
vii tg[N];

ll ans[N][N] = {};

int link[N];

int find(int a){
	return link[a] = (link[a] != a? find(link[a]) : a);
}

bool unite(int a, int b){
	a = find(a); b = find(b);
	if (a == b) return false;
	link[a] = b;
	return true;
}

int f[N];

void DFS(int v, int p = -1){
	for (auto u: tg[v]) if (u.st != p){
		f[u.st] = max(f[v], u.nd);		
		DFS(u.st, v);
	}
}

void minimize(ll &x, ll val){
	if (x == -1 || x > val) x = val;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> sub;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	
	for (int i = 1; i <= m; i++){
		int a, b, c; cin >> a >> b >> c;
		edl.pb(edge(a, b, c));
	}
	
	sort(all(edl), [](edge a, edge b){
		return a.w < b.w;
	});
	
	memset(ans, -1, sizeof ans);
	
	vl b(w + 1, w + n + 1);
	
	sort(all(b));
	
	for (auto wi: b){
		for (int i = 1; i <= n; i++) link[i] = i, tg[i].clear();;
		for (auto e: edl) if (w[e.a] <= wi && w[e.b] <= wi)
			if (unite(e.a, e.b)){
				tg[e.a].pb({e.b, e.w});
				tg[e.b].pb({e.a, e.w});
			}
			
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) f[j] = -1;
			f[i] = 0;
			DFS(i);
			for (int j = 1; j <= n; j++) if (f[j] >= 0)
				minimize(ans[i][j], wi * f[j]);
		}
	}
	
	for (int i = 1; i <= n; i++){
		ll sum = 0;
		for (int j = 1; j <= n; j++){
			sum += ans[i][j];
		}
		cout << sum << " ";
	}
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!