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

bool const SINGLE_TEST = 0;

int const N = 2e5 + 1;

int n, m;

vi g[N];

int clr[N];

void DFS(int v, int c){
	if (clr[v]) return;
	clr[v] = c;
	for (auto u: g[v]) DFS(u, c ^ 3);
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) g[i].clear(), clr[i] = 0;
	
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);

	}
	
	DFS(1, 1);
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++)
		if (clr[i] == 1) a++; else b++;
	
	int x = 1;
	if (a > b) x ^= 3, swap(a, b);
	
	cout << a << "\n";
	for (int i = 1; i <= n; i++)
		if (clr[i] == x) cout << i << " ";
	
	cout << "\n";	
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