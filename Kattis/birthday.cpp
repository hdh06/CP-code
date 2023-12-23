//https://open.kattis.com/problems/birthday

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

int const N = 101;

int n, m;

vi g[N];

bool vis[N];
int x, y;
void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) if ((v != x || u != y) && (v != y || u != x))
		DFS(u);
}

void solve(){	
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for (int i = 0; i < n; i++)
		for (int j: g[i]){
			memset(vis, 0, sizeof vis);
			x = i, y = j;
			DFS(1);	
			
			for (int i = 0; i < n; i++) if (!vis[i]){
				cout << "Yes\n";
				return ;
			}
		}
	cout << "No\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> n >> m;
	while (n != 0 || m != 0){
		solve();
		cin >> n >> m;
	}
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!