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
#define file "PUZZLE"

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

int const N = 1e5 + 1;

int n;
vi g[10];

int nxt[10];

namespace subcuoi{
	void solve(){
		vii z;
		if (g[5].size()){
			if (g[4].size()) z.pb(mp(4, nxt[4]++));
		}else
			if (g[1].size()) z.pb(mp(1, nxt[1]++));
		
		if (z.size() == 0){
			if (g[5].size() && g[7].size()){
				cout << -1;
				return;
			}
			if (g[6].size() && g[8].size()){
				cout << -1;
				return;
			}
		}
		// debug(".");
		while (1){
			if (z.back().st == 1){
				if (nxt[4] == g[4].size()) break;
				z.pb(mp(4, nxt[4]++));
			}else{
				if (nxt[1] == g[1].size()) break;
				z.pb(mp(1, nxt[1]++));
			}
		}
		if (nxt[4] != g[4].size() || nxt[1] != g[1].size()){
			cout << -1;
			return;
		}
		if (z.back().st == 4 && g[8].size()){
			cout << -1;
			return;
		}
		if (z.back().st == 1 && g[7].size()){
			cout << -1;
			return;
		}


		for (int i = 0; i < 10; i++) sort(all(g[i]));

		vi ans; int pre = 0; int curr = 0;
		if (g[5].size()) ans.pb(g[5][0]), pre = 1;
		if (g[6].size()) ans.pb(g[6][0]), pre = 0;
		vi d;
		for (auto x: g[2]) d.pb(x);
		for (auto x: g[3]) d.pb(x);
		sort(all(d));

		while (ans.size() < n - 1){
			if (pre){
				if (nxt[3] < g[3].size() && g[3][nxt[3]] < g[z[curr].st][z[curr].nd]) ans.pb(g[3][nxt[3]++]);
				else if (curr < z.size()) ans.pb(g[z[curr].st][z[curr].nd]), curr++, pre ^= 1;
				else ans.pb(g[3][nxt[3]++]);
			}else{
				if (nxt[2] < g[2].size() && g[2][nxt[2]] < g[z[curr].st][z[curr].nd]) ans.pb(g[2][nxt[2]++]);
				else if (curr < z.size()) ans.pb(g[z[curr].st][z[curr].nd]), curr++, pre ^= 1;
				else ans.pb(g[2][nxt[2]++]);
			}
		}
		if (g[7].size()) ans.pb(g[7][0]);
		if (g[8].size()) ans.pb(g[8][0]);
		for (auto x: ans) cout << x << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, val; cin >> x >> val;
		g[x].pb(val);
	}

	subcuoi::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!