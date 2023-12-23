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
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 2e5 + 1;

int n;
vi g[N];

ii dp[N][2];
bool trace[N][2];

bool cmp(ii a, ii b){
	if (a.st != b.st) return a.st > b.st;
	return a.nd < b.nd;
}

ii DFS(int v, int p, int pre){
	if (dp[v][pre].st != -1) return dp[v][pre];
	ii ans1 = {0, 1 + pre}, ans2 = {1, pre ^ 1};
	for (auto u: g[v]) if (u != p){
		ii e = DFS(u, v, 0);
		ans1.st += e.st;
		ans1.nd += e.nd;
	}
	if (pre == 1){
		trace[v][pre] = 0;
		return dp[v][pre] = ans1;
	}
	for (auto u: g[v]) if (u != p){
		ii e = DFS(u, v, 1);
		ans2.st += e.st;
		ans2.nd += e.nd;
	}
	if (cmp(ans1, ans2)){
		trace[v][pre] = 0;
		return dp[v][pre] = ans1;
	}
	trace[v][pre] = 1;
	return dp[v][pre] = ans2;
}

int w[N]; 

void calc(int v, int p, int pre){
	w[v] = trace[v][pre] ^ 1;
	for (auto u: g[v]){
		if (u != p)
			calc(u, v, trace[v][pre]);
		if (trace[v][pre])w[v] += w[u];
	}
}

void solve(){
	cin >> n;
	
	if (n == 2){
		cout << "2 2\n1 1";
		return;
	}
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	memset(dp, -1, sizeof dp);
	
	ii ans = DFS(1, -1, 0);
	
	cout << ans.st << " " << ans.nd - trace[1][0] << "\n";
	
	calc(1, -1, 0);
	for (int i = 1; i <= n; i++)
		cout << w[i] << " ";
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