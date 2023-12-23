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

int const N = 5e4 + 1;
int const K = 26;

string s;
vii g[N + K * K];


bool minimize(int &x, int v){
	if (x == -1 || x > v){
		x = v;
		return true;
	} 
	return false;
}

void solve(){	
	cin >> s;
	int n = s.size();
	for (int i = 1; i < n; i++){
		if (i + 1 < n){
			g[i].pb({i + 1, 1});
			g[i + 1].pb({i, 1});
		}
		
		int z = N + (s[i - 1] - 'a') * 26 + (s[i] - 'a');

		g[i].pb({z, 1});
		g[z].pb({i, 0});
	}
	
	int q; cin >> q;
	vii qrs;
	int ans[N];
	for (int i = 0; i < q; i++){
		int a, b; cin >> a >> b;
		qrs.pb({a, b});
		ans[i] = abs(a - b);
	}
	
	int dis[N + K * K];
	deque<int> que;
	
	for (int i = N; i < N + K * K; i++){
		memset(dis, -1, sizeof dis);
		que.pb(i);
		dis[i] = 0;
		while (!que.empty()){
			int v = que.front(); que.pof();
			for (ii u: g[v])
				if (minimize(dis[u.st], dis[v] + u.nd)){
					if (u.nd) que.pb(u.st);
					else que.pf(u.st);
				}
		}
		
		for (int k = 0; k < q; k++) if (dis[qrs[k].st] != -1 && dis[qrs[k].nd] != -1)
			minimize(ans[k], dis[qrs[k].st] + dis[qrs[k].nd] + 1);
	}
	
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	
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