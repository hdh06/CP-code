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

int const N = 1e5 + 5;

string s;

vi g[N];

int ans = 1;

int sz[N];

int dp[N];

void DFS(int v){
	// debug(v);
	// if (g[v].size() == 0) sz[v] = 1;
	for (auto u: g[v])
		DFS(u);	
	if (g[v].size()){
		int pos = 0, minn = INT_MAX;
		// for (int i = 0; i < g[v].size(); i++) if (g[g[v][pos]].size() < g[g[v][i]].size()) pos = i;
		for (int i = 0; i < g[v].size(); i++){
			int z = 0;
			for (int j = 0; j < g[v].size(); j++) z = max(z, dp[g[v][j]] + j);
			if (z < minn){
				minn = z;
				pos = i;
			}
			// debug(g[v], z, pos, minn);
			rotate(g[v].begin(), g[v].begin() + 1, g[v].end());
		}
		rotate(g[v].begin(), g[v].begin() + pos, g[v].end());

		dp[v] = minn; 
	}else dp[v] = 1;
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
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
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
	
	DFS(n);
	
	rebuild(n);
	
	cout << dp[n] << "\n" << f;

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!