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
#define file "countpath"

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
int const MOD = 998244353;

struct edge{
	int v, b, l;
	edge(){}
	edge(int v, int b, int l) :v(v), b(b), l(l) {}
};

int sub;
int n, m;
vector<edge> g[N];

namespace sub2{
	int f[N];
	
	int cnt = 0;
	void DFS(int v, int pb, int pl){


		for (auto e: g[v]) if (pb < e.b && pl < e.l)
			DFS(e.v, e.b, e.l);
	}
	
	void solve(){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			memset(vis, 0, sizeof vis);
			cnt = 0;
			DFS(i, 0, 0);
			
			(ans += cnt) %= MOD;
			debug(i, cnt);
		}
		cout << ans << "\n";
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
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, b, l; cin >> x >> y >> b >> l;
		g[x].pb(edge(y, b, l));
		// g[y].pb(edge(x, b, l));
	}
	
	sub2::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!