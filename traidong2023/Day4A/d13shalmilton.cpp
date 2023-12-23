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
#define file "flie"

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

int const N = 2e5 + 1;

int n;

vi g[26][26];
int nxt[26][26];

vi path;

void DFS(int v){
	for (int u = 0; u < 26; u++)
		for (int &i = nxt[v][u]; i < g[v][u].size();){
			i++;
			DFS(u);
			path.pb(u);
		}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n;
	int pos = 0;
	for (int i = 1; i <= n; i++){ 
		string s; cin >> s;
		int x = s[0] - 'a';
		int y = s.back() - 'a';
		g[x][y].pb(i);
		pos = x;
	}
	
	DFS(pos);
	path.pb(pos);
	
	reverse(all(path));
	memset(nxt, 0, sizeof nxt);
	
	vi ans;
	
	for (int i = 1; i < path.size(); i++){
		int &k = nxt[path[i - 1]][path[i]];
		ans.pb(g[path[i - 1]][path[i]][k]);
		k++;
	}
	
	if (ans.size() < n){
		cout << -1;
		return 0;
	}
	
	for (auto x: ans) cout << x << " ";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!