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
int const L = 19; 

int n;
vii g[N];

int k;

int h[N], p[N][L];

ll f[N];

void DFS(int v){
	for (auto u: g[v]) if (u.st != p[v][0]){
		h[u.st] = h[v] + 1;
		p[u.st][0] = v;
		for (int i = 1; i < L; i++)
			p[u.st][i] = p[p[u.st][i - 1]][i - 1];
		DFS(u.st);
	}
}

int LCA(int a, int b){
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int i = 0; i < L; i++) if (k & (1 << i))
		b = p[b][i];
		
	if (a == b) return a;
	
	for (int i = L - 1; i >= 0; i--)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
			
	return p[a][0];
}

int ans[N];

void calc(int v){
	for (auto u: g[v]) if (u.st != p[v][0]){
		calc(u.st);
		ans[u.nd] += f[u.st];
		f[v] += f[u.st];
	}
}

void solve(){	
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb({b, i});
		g[b].pb({a, i});
	}
	
	DFS(1);
	
	cin >> k;
	while (k--){
		int a, b; cin >> a >> b;
		int anc = LCA(a, b);
		f[a]++;
		f[b]++;
		f[anc] -= 2;
	}
	
	calc(1);
	for (int i = 1; i < n; i++)
		cout << ans[i] << " ";
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