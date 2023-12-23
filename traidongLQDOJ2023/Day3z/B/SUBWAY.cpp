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
#define file "SUBWAY"

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

int n, m;
int p[N];
vi g[N];

namespace sub1{
	void solve(){
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++){
			int sum = 0;
			vb vis(n + 1, 0);
			for (int i = 1; i <= n; i++) if (mask & (1 << (i - 1))){
				sum += p[i];
				for (auto u: g[i]) if (vis[u]){
					sum = 0;
					break;
				}
				vis[i] = 1;
			}
			
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
}

namespace sub2{
	vi path;
	void DFS(int v, int p = -1){
		path.pb(v);
		for (auto u: g[v]) if (u != p)
			DFS(u, v);
	}

	int dp[N];

	void solve(){
		int pos;
		for (int i = 1; i <= n; i++) if (g[i].size() == 1) pos = i;

		path.pb(0);
		DFS(pos);

		dp[0] = 0;
		dp[1] = p[path[1]];
		for (int i = 2; i <= n; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + p[path[i]]);
		cout << dp[n] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	if (n <= 20)
		sub1::solve();
	else
		sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!