//https://usaco.org/index.php?page=viewproblem2&cpid=920

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
#define file "revegetate"

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

struct edge{
	int x; char type;
	edge(){}
	edge(int x, char type) :x(x), type(type) {}
};

int const N = 1e5 + 1;

int n, m;
vector<edge> g[N];

int clr[N];
bool DFS(int v, int c){
	clr[v] = c;
	bool ans = 1;
	for (auto u: g[v]){
		if (clr[u.x]){
			if (u.type == 'D' && c == clr[u.x]) ans = 0;
			if (u.type == 'S' && c != clr[u.x]) ans = 0;
		}else{
			ans &= DFS(u.x, u.type == 'S'? c: c ^ 3);
		}
	}
	return ans;
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		char type; int a, b; cin >> type >> a >> b;
		g[a].pb(edge(b, type));
		g[b].pb(edge(a, type));
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (!clr[i]){
		if (DFS(i, 1)) cnt++;
		else{
			cout << 0;
			return;
		}
	}
	cout << 1;
	for (int i = 1; i <= cnt; i++) cout << 0;
}	

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "funnyline";
	#else
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!