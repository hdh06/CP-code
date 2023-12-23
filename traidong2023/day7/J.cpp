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
#define file "shopping"

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

int const N = 5001;

int n, b;

int d[N], c[N], p[N];

namespace sub1{
	void solve(){
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++){
			ll sum = 0;
			for (int i = 1; i <= n; i++) if (mask & (1 << (i - 1))){
				if (i > 1 && (mask & (1 << (p[i] - 1)))) sum += c[i] - d[i];
				else sum += c[i] - (i == 1? d[i]: 0);
			}
			if (sum <= b)
				ans = max(ans, __builtin_popcount(mask));
		}
		cout << ans;
	}
}

namespace sub3{
	void minimize(ll &x, ll v){
		if (x == -1 || x > v) x = v;
	}
	
	vi g[N], rg[N];
	
	ll dp[N][N][2];
	
	vi ord;
	void DFS(int v){
		for (auto u: g[v])
			DFS(u);
		ord.pb(v);
	}
	
	void solve(){
		for (int i = 1; i <= n; i++){
			g[p[i]].pb(i);
			rg[i].pb(p[i]);
		}
		
		memset(dp, -1, sizeof dp); 
		
		for (auto v: ord) for (int k = 0; k <= n; k++){
			if (k == 1) dp[v][k][1] = 0;
			if (k == 0) dp[v][k][0] = 0;
			for (int cur = 0; cur <= 1; cuir++) if (dp[i][k][cur] != -1)
				for (auto u: rg[v])
					for (int nxt = 0; nxt <= 1; nxt++){
						if (cur == 1 && nxt == 1) minimize(dp[u][k + (nxt == 1)][nxt], dp[v][k][cur] + c[v] - d[v]);
						else minimize(dp[u][k + (nxt == 1)][nxt], dp[v][k][cur] + (cur == 1? c[v]: 0));
					}
					
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> n >> b;
	for (int i = 1; i <= n; i++){
		cin >> c[i] >> d[i];
		if (i > 1) cin >> p[i];
	}
	
	// if (n <= 20)
		// sub1::solve();
	// else cout << min(n, b / *min_element(c + 1, c + n + 1));
	
	sub3::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!