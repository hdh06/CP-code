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
#define file "f"

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

int const N = 1e5 + 5;

string s;

vi g[N];

int ans = 1;

int sz[N];
bool vis[N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	// debug(v);
	// if (g[v].size() == 0) sz[v] = 1;
	if (g[v].size()){
		int pos = 0, minn = INT_MAX;
		// for (int i = 0; i < g[v].size(); i++) if (g[g[v][pos]].size() < g[g[v][i]].size()) pos = i;
		for (int i = 0; i < g[v].size(); i++){
			int z = 0;
			for (int j = 0; j < g[v].size(); j++) z = max(z, (int)g[g[v][j]].size() + j);
			if (z < minn){
				minn = z;
				pos = i;
			}
			// debug(g[v], z, pos, minn);
			rotate(g[v].begin(), g[v].begin() + 1, g[v].end());
		}
		rotate(g[v].begin(), g[v].begin() + pos, g[v].end());
		ans = max(ans, minn);
	}
	for (auto u: g[v])
		DFS(u);	
}

string f;

void rebuild(int v){
	for (auto u: g[v]) rebuild(u);
	if (g[v].size() == 0) f.pb('a');
	else f.pb(g[v].size() + '0');
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	// #endif

	cin >> s;
	int n = s.size();
	s = ' ' + s;

	stack<int> st;
	for (int i = 1; i <= n; i++){
		if (s[i] == 'a') st.push(i);
		else{
			s[i] -= '0';
			for (int j = 1; j <= s[i]; j++){
				g[i].pb(st.top());
				st.pop();
			}
			reverse(all(g[i]));
			st.push(i);
		}
	}
	
	for (int i = n; i >= 1; i--) if (!vis[i]){
		g[n + 1].pb(i);
		DFS(i);
	}
	reverse(all(g[n + 1]));
	DFS(n + 1);
	ans = max(ans, (int)g[n + 1].size());
	
	rebuild(n + 1);
	
	f.erase(f.end() - 1);
	
	cout << ans;// << "\n" << f;

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!