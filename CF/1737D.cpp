#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<ll, ll> ii;
typedef array<ll, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;
int const N = 501;

int n, m;
vector<ii> g[N];
ll dis1[N], disn[N];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	vector<iii> e;
	for (int i = 1; i <= m; i++){
		int a, b, w; cin >> a >> b >> w;
		g[a].pb({b, w});
		g[b].pb({a, w});
		e.pb({a, b, w});
	}
	
	for (int i = 1; i <= n; i++)
		dis1[i] = disn[i] = LLONG_MAX;
	
	dis1[1] = 0;
	priority_queue<ii> que;
	que.push({0, 1});
	
	while (!que.empty()){
		int v = que.top().nd;
		que.pop();
		for (auto u: g[v])
			if (dis1[u.st] > dis1[v] + u.nd){
				dis1[u.st] = dis1[v] + u.nd;
				que.push({-dis1[u.st], u.st});
			}
	}
	
	disn[n] = 0;
	que.push({0, n});
	
	while (!que.empty()){
		int v = que.top().nd;
		que.pop();
		for (auto u: g[v])
			if (disn[u.st] > disn[v] + u.nd){
				disn[u.st] = disn[v] + u.nd;
				que.push({-disn[u.st], u.st});
			}
	}
	
	ll ans = dis1[n];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (auto x: g[i])
				ans = min(ans, dis1[i] + 2 * x.nd + disn[x.st]);
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!