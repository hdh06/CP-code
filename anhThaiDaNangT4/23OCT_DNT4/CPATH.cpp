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
#define file "fiel"

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

bool const SINGLE_TEST = 1;

int const N = 1e5 + 1;

int n, m;
vii g[N];

ii p[N];

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	
	for (int i = 1; i <= n; i++)
		sort(all(g[i]), [](ii a, ii b){
			return a.nd < b.nd;
		});
	
	queue<int> que;
	que.push(1);
	
	memset(p, -1, sizeof p);
	
	p[1] = {0, 0};
	
	while (!que.empty()){
		int v = que.front(); que.pop();
		
		for (auto u: g[v]) if (p[u.st].st == -1){
			p[u.st] = {v, u.nd};
			que.push(u.st);
		}
		
	}
	vi ans;
	ii z = p[n];
	while (z.st){
		ans.pb(z.nd);
		z = p[z.st];
	}
	
	reverse(all(ans));
	
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
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
}//khong phai _HDH, _HDH ko xai template!!!